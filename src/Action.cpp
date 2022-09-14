#include "Action.h"

Action::Action() {
}

Action::Action(std::string n) {
    this->name = n;
}

Action::Action(std::string n, int ac) {
    this->name = n;
    this->action_count = ac;
}

Action::SetCount(int ac) {
    this->action_count = ac;
}

Action::AddEffect(string name, TAG tag, RESSOURCES res, int value, COMPARATOR c) {
    Effect* e = new Effect(name, tag, res, value, c);
    this->effects.push_back(e);
}

Action::AddPrecondition(string name, TAG tag, RESSOURCES res, int value, COMPARATOR c) {
    Precondition* p = new Precondition(name, tag, res, value, c);
    this->preconditions.push_back(p);
}

Action::GetName() {
    if(this->name.empty()) {
        cout << "L'action n'a pas de nom." << endl;
    } else {
        cout << this->name << endl;
    }
}

Action::GetCount() {
    if(!this->action_count) {
        cout << "L'action n'a pas de cout." << endl;
    } else {
        cout << this->action_count << endl;
    }
}

Action::GetAllEffects(WorldState& ws) {
    for(int i = 0; i < effects.size(); i++)
    {
        effects[i]->Apply(ws);
    }
}

vector<Effect*> Action::GetEffects() {
    return this->effects;
}

vector<Precondition*> Action::GetAllPreconditions() {
    return this->preconditions;
}

vector<Action*> Action::FindActionWithTagEffect(TAG tag, vector<Action*> allActions)
{
    vector<Action*> res = vector<Action*>();
    for(int i = 0; i < allActions.size(); i++)
    {
        for(int j = 0; j < allActions[i]->GetEffects().size(); j++)
        {
            if(allActions[i]->GetEffects()[j]->tag == tag)
            {
                res.push_back(allActions[i]);
                break;
            }
        }
    }

    return res;
}


void Action::Process(WorldState& ws, vector<Action*> allActions, vector<Action*> *path)
{
    bool isActionValid = true;
    bool precoBool = false;
    for(int j = 0; j < this->preconditions.size(); j++)
    {
        precoBool = this->preconditions[j]->CompareRessources(ws);
        if(!precoBool){
            vector<Action*> neighb = FindActionWithTagEffect(this->preconditions[j]->tag, allActions);
            for(int m = 0; m < neighb.size(); m++)
            {
                neighb[m]->Process(ws, allActions, path);
            }
        }
        isActionValid *= precoBool;

    }
    if(isActionValid)
    {
        this->GetAllEffects(ws);
        path->push_back(this);
    }
    return;
}

Action::~Action() {
    //dtor
}
