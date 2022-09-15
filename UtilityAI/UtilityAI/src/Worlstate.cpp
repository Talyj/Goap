#include "Worlstate.h"

Worlstate::Worlstate()
{
    wood, food, rock, house, religious_building, city_hall = 0;
    villager = 5;
}

Worlstate::Worlstate(const int nb_wood, const int nb_rock, const int nb_food, const int nb_house, const int nb_religious_building, const int nb_city_hall, const int nb_villager)
{
    wood = nb_wood;
    rock = nb_rock;
    food = nb_food;
    villager = nb_villager;

    house = nb_house;
    religious_building = nb_religious_building;
    city_hall = nb_city_hall;
}

Worlstate::~Worlstate()
{
    //dtor
}

int Worlstate::operator[](const int index)const{
    switch(index){
    case 0:
        return wood;
        break;
    case 1:
        return rock;
        break;
    case 2:
        return food;
        break;
    case 10:
        return wood;
        break;
    case 11:
        return rock;
        break;
    case 12:
        return food;
        break;
    }
}
