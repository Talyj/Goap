#include "Action.h"

Action::Action() {
    this->name = "Action non nommée";
    this->action_cost = 0;
}

Action::Action(std::string n) {
    this->name = n;
}

Action::Action(std::string n, int ac) {
    this->name = n;
    this->action_cost = ac;
}

//Attribuer le cout de l'action
Action::SetCost(int ac) {
    this->action_cost = ac;
}

//Ajoute un effet à l'action
Action::AddEffect(string name, TAG tag, RESSOURCES res, int value, COMPARATOR c) {
    Effect* e = new Effect(name, tag, res, value, c);
    this->effects.push_back(e);
}

//Ajoute une pre-condition à l'action
Action::AddPrecondition(string name, TAG tag, RESSOURCES res, int value, COMPARATOR c) {
    Precondition* p = new Precondition(name, tag, res, value, c);
    this->preconditions.push_back(p);
}

//Retourne le nom de l'action
string Action::GetName() {
    return name;
}

//Retourne le cout de l'action
int Action::GetCost() {
    return action_cost;
}

//Applique tous les effets
Action::GetAllEffects(WorldState& ws) {
    for(int i = 0; i < effects.size(); i++)
    {
        effects[i]->Apply(ws);
    }
}

//Retourne tous les effets
vector<Effect*> Action::GetEffects() {
    return this->effects;
}

//Retourne toutes les predictions
vector<Precondition*> Action::GetAllPreconditions() {
    return this->preconditions;
}

//Renvoie une liste d'action qui à au moins un effet avec le tag passer en paramètre
vector<Action*> Action::FindActionWithTagEffect(TAG tag, vector<Action*> allActions)
{
    vector<Action*> res = vector<Action*>();
    for(int i = 0; i < allActions.size(); i++)
    {
        for(int j = 0; j < allActions[i]->GetEffects().size(); j++)
        {
            if(allActions[i]->GetEffects()[j]->GetTag() == tag)
            {
                res.push_back(allActions[i]);
                break;
            }
        }
    }

    return res;
}

//Simulation pour trouver le meilleur chemin à emprunter
pair<bool, int> Action::Simulate(WorldState& ws, vector<Action*> allActions, vector<Action*> *path)
{
    int cost = 0;
    bool isActionValid = true;
    bool precoBool = false;

    for(int j = 0; j < this->preconditions.size(); j++)
    {
        precoBool = this->preconditions[j]->CompareRessources(ws);
        if(!precoBool){
            vector<Action*> neighb = FindActionWithTagEffect(this->preconditions[j]->GetTag(), allActions);
            if(neighb.size())
            {
                int minCost = INT_MAX;
                Action* minCostAction = nullptr;
                int currentCost = 0;
                WorldState bestSimulationWS = ws;

                //Boucle des actions enfants
                for(int m = 0; m < neighb.size(); m++)
                {
                    WorldState simulationWS = ws;
                    currentCost = neighb[m]->Simulate(ws, allActions, path).second;
                    if(currentCost < minCost)
                    {
                        minCost = currentCost;
                        minCostAction = neighb[m];
                        bestSimulationWS = simulationWS;
                    }
                }
                path->push_back(minCostAction);
                cost += minCost;

                //Simule le monde avec son nouvelle état
                this->GetAllEffects(bestSimulationWS);
                precoBool = this->preconditions[j]->CompareRessources(bestSimulationWS);
            }
            else{
                isActionValid = false;
                cost = INT_MAX;
            }

        }

        isActionValid *= precoBool;

    }

    if(isActionValid)
    {
        cost += this->GetCost();
    }

    return make_pair(isActionValid, cost);
}

//Procéder aux effets de l'action
int Action::Process(WorldState& ws, vector<Action*> allActions, vector<Action*> *path)
{

    pair<bool, int> simulation = this->Simulate(ws, allActions, path);
    int cost = simulation.second;

    if(simulation.first)
    {
        path->push_back(this);
        cost += this->action_cost;
    }
    return simulation.second ;
}

Action::~Action() {
    //dtor
}
