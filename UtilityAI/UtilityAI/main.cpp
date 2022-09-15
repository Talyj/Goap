#include <iostream>
#include "Action.h"

using namespace std;

int main()
{
    //std::list<Action*> my_actions;

    Action* wood = new Action("gathering wood");
    Action* rock = new Action("gathering rock");
    Action* food = new Action("gathering food");

    Action* house = new Action("building house");
    Action* religious_Action = new Action("building religious_Actioning");
    Action* city_hall = new Action("building city_hall");

    Worlstate* ws = new Worlstate(0, 0, 0, 0, 0, 0);


    return 0;
}
