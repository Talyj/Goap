#include <iostream>
#include "Action.h"



using namespace std;

int main()
{
    //std::list<Action*> my_actions;

    Action* wood = new Action("gathering wood", WOOD);
    Action* rock = new Action("gathering rock", ROCK);
    Action* food = new Action("gathering food", FOOD);

    Action* house = new Action("building house", HOUSE);
    Action* religious_Action = new Action("building religious_Actioning", RELIGIOUS_BUILDING);
    Action* city_hall = new Action("building city_hall", CITY_HALL);

    vector<Action*> all_actions = vector<Action*>();

    Worlstate* ws = new Worlstate(0, 0, 0, 0, 0, 0, 0);

    if(house->HaveEnoughResources(ws, house->res_type)){

    }

    return 0;
}
