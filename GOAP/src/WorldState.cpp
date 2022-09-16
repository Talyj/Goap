#include "WorldState.h"

WorldState::WorldState(const int nb_villagers, const int nb_rocks, const int nb_woods, const int nb_houses, const int nb_gold) {
    this->villagers = nb_villagers;
    this->rocks = nb_rocks;
    this->woods = nb_woods;
    this->houses = nb_houses;
    this->gold = nb_gold;
}

void WorldState::SetNewValue(const int index, int value) {
    switch(index){
    case 0:
        this->woods = value;
        break;
    case 1:
        this->rocks = value;
        break;
    case 2:
        this->villagers = value;
        break;
    case 3:
        this->houses = value;
        break;
    case 4:
        this->gold = value;
        break;
    }
}

WorldState WorldState::operator=(const WorldState& ws) {
    return WorldState(ws[2], ws[1], ws[0], ws[3], ws[4]);
}

int WorldState::operator[](const int index)const {
    switch(index){
    case 0:
        return this->woods;
        break;
    case 1:
        return this->rocks;
        break;
    case 2:
        return this->villagers;
        break;
    case 3:
        return this->houses;
        break;
    case 4:
        return this->gold;
        break;
    }
}

WorldState::~WorldState() {}


