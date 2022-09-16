#include <iostream>
#include "Action.h"



using namespace std;

int main()
{
    //std::list<Action*> my_actions;

    Action* wood = new Action("gathering wood", WOOD);
    Action* rock = new Action("gathering rock", ROCK);
    Action* food = new Action("gathering food", FOOD);
    Action* villager = new Action("gathering food", VILLAGER);

    Action* house = new Action("building house", HOUSE);
    Action* religious_build = new Action("building religious_Actioning", RELIGIOUS_BUILDING);
    Action* city_hall = new Action("building city_hall", CITY_HALL);

    vector<Action*> all_actions = vector<Action*>();
    all_actions.push_back(wood);
    all_actions.push_back(rock);
    all_actions.push_back(food);
    all_actions.push_back(villager);
    all_actions.push_back(house);
    all_actions.push_back(religious_build);
    all_actions.push_back(city_hall);

    Worlstate ws = Worlstate();
    while(ws[HOUSE] < NB_FINAL_HOUSES && ws[RELIGIOUS_BUILDING] < NB_FINAL_RELIGIOUS_BUILDING && ws[CITY_HALL] < NB_FINAL_CITY_HALL)
    {

        for(int i = 0; i < all_actions.size(); i++){

            if(all_actions[i].res_type < 0){
                //Resources
                if(all_actions[i]->HaveEnoughResources(ws, all_actions[i]->res_type)){

                }
            }else{
                //Buildings
                if(all_actions[i]->HaveEnoughResources(ws, all_actions[i]->bui_type)){

                }
            }
        }
    }


    return 0;
}
