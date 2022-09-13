#include <iostream>
#include "Action.h"
#include "WorldState.h"

using namespace std;

#define NB_MAISON_FINAL = 15;

int main()
{
    WorldState ws = WorldState(15,0,0,0);

    //Actions
    Action* couperBois = new Action("Couper du bois", 1);
    Action* minerPierre = new Action("Miner de la pierre", 1);
    Action* construireMaison = new Action("Construire une maison", 5);

    //Effets
    couperBois->AddPrecondition("Ajouter une quantité de bois au stock");
    minerPierre->AddPrecondition("Ajouter une quantité de pierre au stock");
    construireMaison->AddPrecondition("Ajouter une maison au village");

    //Pré-conditions
    couperBois->AddPrecondition("Avoir des villageois disponible");
    minerPierre->AddPrecondition("Avoir des villageois disponible");
    construireMaison->AddPrecondition("Avoir des villageois disponible");
    construireMaison->AddPrecondition("Avoir 10 de bois minimum");
    construireMaison->AddPrecondition("Avoir 10 de pierre minimum");



    cout << "World State : \{ Nombre de maison = " << ws[RESSOURCES::HOUSE] << " - Nombre de villageois = " <<  ws[RESSOURCES::VILLAGER] << " - Nombre de pierre = " <<  ws[RESSOURCES::ROCK] << " - Nombre de bois = " <<  ws[RESSOURCES::WOOD] << " \}" << endl;

    return 0;
}
