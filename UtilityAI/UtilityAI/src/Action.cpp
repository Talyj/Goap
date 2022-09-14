#include "Action.h"

Action::Action(const std::string res_name)
{
    name = res_name;
}

Action::~Action()
{
    //dtor
}

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

void Action::Update(const Worlstate ws, const BUILDING bui)
{
    int time_to_build = 0;
    int wood_needed = 0;
    int rock_needed = 0;

    switch(bui){
    case HOUSE:
        time_to_build = 0.4;
        wood_needed = 0.3;
        rock_needed = 0.3;
        break;
    case RELIGIOUS_BUILDING:
        time_to_build = 0.6;
        wood_needed = 0.4;
        rock_needed = 0.5;
        break;
    case CITY_HALL:
        time_to_build = 0.8;
        wood_needed = 0.3;
        rock_needed = 0.6;
        break;
    }
    utility_score = ((((ws[bui] / 100) - 1) * -1) + time_to_build + wood_needed) / 3;
}
