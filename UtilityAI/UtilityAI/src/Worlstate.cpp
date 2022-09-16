#include "Worlstate.h"



Worlstate::Worlstate()
{
    wood, food, rock, house, religious_building, city_hall = 0;
    villager = 5;

    NB_WOOD = vector<int>();
    NB_ROCK = vector<int>();
    NB_FOOD = vector<int>();

    /*NB_ROCK = new char {
        "5", //HOUSE
        "30", //RELIGIOUS_BUILD
        "50"  // CITY_HALL
    };

    NB_FOOD = new char {
        "5", //HOUSE
        "10", //RELIGIOUS_BUILD
        "20"  // CITY_HALL
    };*/
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
    case 10:
        return wood;
    case 11:
        return rock;
    case 12:
        return food;
    case 13 :
        return villager;
    case 0:
        return house;
    case 1:
        return religious_building;
    case 2:
        return city_hall;
    }
}
