#include "Action.h"
#include <iostream>

Action::Action(const std::string res_name, const RESSOURCES type, const BUILDING other_type)
{
    this->name = res_name;
    this->res_type = type;
    this->bui_type = other_type;
}

Action::~Action()
{
    //dtor
}

//Check if the building in parameters can be built with the current resources
bool Action::HaveEnoughResources(const Worlstate ws, const BUILDING bui, const RESSOURCES res)
{
    switch(bui){
        case HOUSE:
            if(ws.wood >= ws.NB_WOOD[(int)bui] && ws.rock >= ws.NB_ROCK[(int)bui] && ws.food >= ws.NB_FOOD[(int)bui]){
                return true;
            }
            return false;
        case RELIGIOUS_BUILDING:
            if(ws.wood >= ws.NB_WOOD[(int)bui] && ws.rock >= ws.NB_ROCK[(int)bui] && ws.food >= ws.NB_FOOD[(int)bui]){
                return true;
            }
            return false;
        case CITY_HALL:
            if(ws.wood >= ws.NB_WOOD[(int)bui] && ws.rock >= ws.NB_ROCK[(int)bui] && ws.food >= ws.NB_FOOD[(int)bui]){
                return true;
            }
            return false;
        default:
            return true;
    }
}

//This will be called every loop to update the resource in parameter its utility score
float Action::Update(const Worlstate ws, const RESSOURCES res)
{
    switch(res){
    case WOOD:
        return (((((float)ws[res] / 100) - 1) * -1) + (float)(ws.wood_needed / 100)) / 2;
    case ROCK:
        return (((((float)ws[res] / 100) - 1) * -1) + (float)(ws.rock_needed / 100)) / 2;
    case FOOD:
        return (((((float)ws[res] / 100) - 1) * -1) + (float)(ws.food_needed / 100)) / 2;
    case VILLAGER:
        return (((((float)ws[res] / 100) - 1) * -1) + (float)(ws.villager_needed / 100)) / 2;
    }
}

//This will be called every loop to update the building in parameter its utility score
float Action::Update(const Worlstate ws, const BUILDING bui)
{
    switch(bui){
    case HOUSE:
        return (((((float)ws[bui] / 100) - 1) * -1) + (float)(ws.house_needed / ws.villager)) / 2;
    case RELIGIOUS_BUILDING:
        return (((((float)ws[bui] / 100) - 1) * -1) + (float)(ws.religious_building / ws.villager * 10)) / 2;
    case CITY_HALL:
        return (((((float)ws[bui] / 100) - 1) * -1) + (float)(ws.city_hall / ws.villager * 7)) / 2;
    }
}


