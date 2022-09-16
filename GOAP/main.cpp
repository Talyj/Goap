#include <iostream>
#include <windows.h>
#include "Action.h"
#include "WorldState.h"

#define NB_MAISON_FINAL 15

using namespace std;

int main()
{
    WorldState ws = WorldState(15,0,0,0,100);

    //Actions
    Action* couperBois = new Action("Couper du bois", 2);
    Action* achatBois = new Action("Acheter du bois", 1);
    Action* minerPierre = new Action("Miner de la pierre", 1);
    Action* construireMaison = new Action("Construire une maison", 5);

    //Effets
    couperBois->AddEffect("Ajouter une quantité de bois au stock", TAG::INCREASE_WOOD, RESSOURCES::WOOD, 1, COMPARATOR::HIGHER );
    achatBois->AddEffect("Ajouter une quantité de bois au stock", TAG::INCREASE_WOOD, RESSOURCES::WOOD, 1, COMPARATOR::HIGHER );
    achatBois->AddEffect("Donner l'argent pour le bois", TAG::DECREASE_GOLD, RESSOURCES::GOLD, 1, COMPARATOR::HIGHER );
    minerPierre->AddEffect("Ajouter une quantité de pierre au stock", TAG::INCREASE_ROCK, RESSOURCES::ROCK, 1, COMPARATOR::HIGHER );
    construireMaison->AddEffect("Ajouter une maison au village", TAG::INCREASE_HOUSE, RESSOURCES::HOUSE, 1, COMPARATOR::HIGHER );
    construireMaison->AddEffect("Utiliser du bois", TAG::DECREASE_WOOD, RESSOURCES::WOOD, 10, COMPARATOR::LOWER );
    construireMaison->AddEffect("Utiliser du pierre", TAG::DECREASE_ROCK, RESSOURCES::ROCK, 10, COMPARATOR::LOWER );

    //Pré-conditions
    couperBois->AddPrecondition("Avoir des villageois disponible", TAG::INCREASE_VILLAGER, RESSOURCES::VILLAGER, 1, COMPARATOR::HIGHER_OR_EQUAL );
    achatBois->AddPrecondition("Avoir assez d'argent", TAG::INCREASE_GOLD, RESSOURCES::GOLD, 10, COMPARATOR::HIGHER_OR_EQUAL );
    minerPierre->AddPrecondition("Avoir des villageois disponible", TAG::INCREASE_VILLAGER, RESSOURCES::VILLAGER, 1, COMPARATOR::HIGHER_OR_EQUAL );
    construireMaison->AddPrecondition("Avoir des villageois disponible", TAG::INCREASE_VILLAGER, RESSOURCES::VILLAGER, 1, COMPARATOR::HIGHER_OR_EQUAL );
    construireMaison->AddPrecondition("Avoir 10 de bois minimum", TAG::INCREASE_WOOD, RESSOURCES::WOOD, 10, COMPARATOR::HIGHER_OR_EQUAL );
    construireMaison->AddPrecondition("Avoir 10 de pierre minimum", TAG::INCREASE_ROCK, RESSOURCES::ROCK, 10, COMPARATOR::HIGHER_OR_EQUAL );

    vector<Action*> allActions= vector<Action*>();
    allActions.push_back(construireMaison);
    allActions.push_back(couperBois);
    allActions.push_back(minerPierre);
    allActions.push_back(achatBois);



    vector<Action*> actions= vector<Action*>();
    actions.push_back(construireMaison);


    vector<Precondition*> precondition= vector<Precondition*>();
    for(int i = 0; i < actions.size(); i++)
    {
        for(int j = 0; j < actions[i]->GetAllPreconditions().size(); j++)
        {
            precondition.push_back(actions[i]->GetAllPreconditions()[j]);
        }
    }

    vector<Action*> path;
    int cost = 0;

    while(ws[RESSOURCES::HOUSE] != NB_MAISON_FINAL)
    {
        cout << "\nWorld State : \{ Nombre de maison = " << ws[RESSOURCES::HOUSE] << " - Nombre de villageois = " <<  ws[RESSOURCES::VILLAGER] << " - Nombre de pierre = " <<  ws[RESSOURCES::ROCK] << " - Nombre de bois = " <<  ws[RESSOURCES::WOOD] << " \}" << endl;

        path = vector<Action*>();
        for(int i = 0; i < actions.size(); i++)
        {
            cost = actions[i]->Process(ws, allActions, &path);
        }

        cout << "\n- Chemin";
        for(int i = 0; i < path.size(); i++)
        {
            path[i]->GetAllEffects(ws);
            cout << " -> " << path[i]->name;
        }

        cout << " - Cout : " << cost << endl;

        Sleep(500);
    }

    cout << "\nWorld State : \{ Nombre de maison = " << ws[RESSOURCES::HOUSE] << " - Nombre de villageois = " <<  ws[RESSOURCES::VILLAGER] << " - Nombre de pierre = " <<  ws[RESSOURCES::ROCK] << " - Nombre de bois = " <<  ws[RESSOURCES::WOOD] << " \}" << endl;


    return 0;
}
