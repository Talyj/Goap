#include <iostream>
#include "Action.h"
#include "WorldState.h"

#define VILLAGER 0
#define ROCK 1
#define WOOD 2
#define HOUSE 3

using namespace std;

#define NB_MAISON_FINAL = 15;

int nbMaison = 0;
int nbVillageois = 15;
int nbBois = 0;
int nbPierre = 0;

int main()
{
    WorldState ws = WorldState(15,0,0,0);
    Action* a1 = new Action("Test", 5);
    a1->AddPrecondition("Pre-test");

    cout << "World State : \{ Nombre de maison = " << ws[HOUSE] << " - Nombre de villageois = " <<  ws[VILLAGER] << " - Nombre de pierre = " <<  ws[ROCK] << " - Nombre de bois = " <<  ws[WOOD] << " \}" << endl;
    a1->GetAllPreconditions();

    return 0;
}
