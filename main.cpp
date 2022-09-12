#include <iostream>
#include "Action.h"

using namespace std;

#define NB_MAISON_FINAL = 15;

int nbMaison = 0;
int nbVillageois = 15;
int nbBois = 0;
int nbPierre = 0;

int main()
{
    Action* a1 = new Action("Test", 5);
    a1->AddPrecondition("Pre-test");

    cout << "World State : \{ Nombre de maison = " << nbMaison << " - Nombre de villageois = " << nbVillageois << " - Nombre de pierre = " << nbPierre << " - Nombre de bois = " << nbBois << " \}" << endl;
    a1->GetAllPreconditions();

    return 0;
}
