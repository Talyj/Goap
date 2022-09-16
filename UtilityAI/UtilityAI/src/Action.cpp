#include "Action.h"

Action::Action(const std::string res_name, const RESSOURCES type)
{
    name = res_name;
    res_type = type;
}

Action::Action(const std::string res_name, const BUILDING type)
{
    name = res_name;
    bui_type = type;
}

Action::~Action()
{
    //dtor
}

bool Action::HaveEnoughResources(const Worlstate ws, const BUILDING bui)
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
    }
}
//This will be called every loop to update the resource in parameter its utility score
void Action::Update(const Worlstate ws, const RESSOURCES res)
{
    int time_to_gather = 0;
    int resource_weight = 0;

    switch(res){
    case WOOD:
        time_to_gather = 0.2;
        resource_weight = 0.2;
        break;
    case ROCK:
        time_to_gather = 0.3;
        resource_weight = 0.4;
        break;
    case FOOD:
        time_to_gather = 0.1;
        resource_weight = 0.1;
        break;
    }
    utility_score = ((((ws[res] / 100) - 1) * -1) + time_to_gather + resource_weight) / 3;
}

//This will be called every loop to update the building in parameter its utility score
float Action::Update(const Worlstate ws, const BUILDING bui)
{
    int time_to_build = 0;
    int nb_already_built = 0;
    int rock_needed = 0;

    switch(bui){
    case HOUSE:
        if(!HaveEnoughResources(ws, bui)){
            time_to_build, nb_already_built, rock_needed = 1;
        }else{

        }
        nb_already_built = 0.3;
        rock_needed = 0.3;
        return 1;
    case RELIGIOUS_BUILDING:
        time_to_build = 0.6;
        nb_already_built = 0.4;
        rock_needed = 0.5;
        break;
    case CITY_HALL:
        time_to_build = 0.8;
        nb_already_built = 0.3;
        rock_needed = 0.6;
        break;
    }
    return ((((ws[bui] / 100) - 1) * -1) + time_to_build + nb_already_built) / 3;
}

void IncrementValue(Worlstate ws, const string res_name, const bool need_increase){

}


