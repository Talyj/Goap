#include "WorldState.h"

WorldState::WorldState(const int nb_villagers, const int nb_rocks, const int nb_woods, const int nb_houses, const int nb_gold)
{
    villagers = nb_villagers;
    rocks = nb_rocks;
    woods = nb_woods;
    houses = nb_houses;
    gold = nb_gold;
}

WorldState WorldState::operator=(const WorldState& ws)
{
    return WorldState(ws[2], ws[1], ws[0], ws[3], ws[4]);
}

WorldState::~WorldState()
{
    //dtor
}

int WorldState::operator[](const int index)const{
    switch(index){
    case 0:
        return woods;
        break;
    case 1:
        return rocks;
        break;
    case 2:
        return villagers;
        break;
    case 3:
        return houses;
        break;
    case 4:
        return gold;
        break;
    }
}

void WorldState::SetNewValue(const int index, int value)
{
    switch(index){
    case 0:
        woods = value;
        break;
    case 1:
        rocks = value;
        break;
    case 2:
        villagers = value;
        break;
    case 3:
        houses = value;
        break;
    case 4:
        gold = value;
        break;
    }
}


