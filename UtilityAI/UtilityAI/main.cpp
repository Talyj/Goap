#include <iostream>
#include "Action.h"



using namespace std;

//Get the max value from a vector and return the corresponding action* to execute
int GetMaxFromVector(vector<float> value_vector, vector<Action*> return_object, bool is_res)
{
    float max_value = 0;
    int res = 0;
    for(int i = 0; i < value_vector.size(); i++)
    {
        if(value_vector[i] > max_value)
        {
            max_value = value_vector[i];
            if(is_res)
            {
                res = (int)return_object[i]->res_type;
            }
            else {res = (int)return_object[i]->bui_type;}
        }
    }
    return res;
}

int main()
{
    Worlstate ws = Worlstate(0, 0, 0, 0, 0, 0, 5);

    //Action (gather)
    Action* wood = new Action("gathering wood", WOOD, NONES);
    Action* rock = new Action("gathering rock", ROCK, NONES);
    Action* food = new Action("gathering food", FOOD, NONES);
    Action* villager = new Action("gathering food", VILLAGER, NONES);

    //Action (build)
    Action* house = new Action("building house", NONE, HOUSE);
    Action* religious_build = new Action("building religious_Actioning", NONE, RELIGIOUS_BUILDING);
    Action* city_hall = new Action("building city_hall", NONE, CITY_HALL);

    //resources
    vector<Action*> all_resources = vector<Action*>();
    all_resources.push_back(wood);
    all_resources.push_back(rock);
    all_resources.push_back(food);
    all_resources.push_back(villager);
    //buildings
    vector<Action*> all_buildings = vector<Action*>();
    all_buildings.push_back(house);
    all_buildings.push_back(religious_build);
    all_buildings.push_back(city_hall);

    while(ws[HOUSE] < NB_FINAL_HOUSES || ws[RELIGIOUS_BUILDING] < NB_FINAL_RELIGIOUS_BUILDING || ws[CITY_HALL] < NB_FINAL_CITY_HALL)
    {
        vector<float> utility_scores_buildings = vector<float>();
        vector<float> utility_scores_resources = vector<float>();

        //Check if a building can be built during this turn
        for(int i = 0; i < all_buildings.size(); i++)
        {
            utility_scores_buildings.push_back(all_buildings[i]->Update(ws, all_buildings[i]->bui_type));

            if(all_buildings[i]->HaveEnoughResources(ws, all_buildings[i]->bui_type, all_buildings[i]->res_type))
            {
                if(ws[all_buildings[i]->bui_type] >= ws.NB_FINAL_BUILDS[all_buildings[i]->bui_type])
                {
                    continue;
                }
                ws.IncrementValue(all_buildings[i]->bui_type);
                break;
            }
            ws.wood_needed = ws.NB_WOOD[(int)all_buildings[i]->bui_type] - ws.wood;
            if(ws.wood_needed < 0) ws.wood_needed = 0;

            ws.rock_needed = ws.NB_ROCK[(int)all_buildings[i]->bui_type] - ws.rock;
            if(ws.rock_needed < 0) ws.rock_needed = 0;

            ws.food_needed = ws.NB_FOOD[(int)all_buildings[i]->bui_type] - ws.food;
            if(ws.food_needed < 0) ws.food_needed = 0;

            ws.villager_needed = ws.NB_VILLAGER[(int)all_buildings[i]->bui_type] - ws.villager;
            if(ws.villager_needed < 0) ws.villager_needed = 0;
        }
        for(int i = 0; i < all_resources.size(); i++)
        {
            utility_scores_resources.push_back(all_resources[i]->Update(ws, all_resources[i]->res_type));
        }
        cout << "\nWorld State : \{ Nombre de bois = " << ws[RESSOURCES::WOOD] << " - Nombre de pierre = " <<  ws[RESSOURCES::ROCK] << " - Nombre de nourriture = " <<  ws[RESSOURCES::FOOD] << " - Nombre de villageois = " <<  ws[RESSOURCES::VILLAGER] << " - Nombre de maison = " <<  ws[BUILDING::HOUSE] << " - Nombre de mairie = " <<  ws[BUILDING::CITY_HALL] << " - Nombre de religion = " <<  ws[BUILDING::RELIGIOUS_BUILDING] << " \}" << endl;

        ws.IncrementValue(GetMaxFromVector(utility_scores_resources, all_resources, true));

        Sleep(500);
    }
}
