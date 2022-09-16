#include "Worlstate.h"
#include <iostream>



Worlstate::Worlstate()
{
    this->wood, this->food, this->rock, this->house, this->religious_building, this->city_hall = 0;
    villager = 5;

    NB_WOOD = vector<int>();
    NB_WOOD.push_back(10);
    NB_WOOD.push_back(30);
    NB_WOOD.push_back(20);
    NB_ROCK = vector<int>();
    NB_ROCK.push_back(5);
    NB_ROCK.push_back(30);
    NB_ROCK.push_back(50);
    NB_FOOD = vector<int>();
    NB_FOOD.push_back(5);
    NB_FOOD.push_back(10);
    NB_FOOD.push_back(20);
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

    NB_WOOD = vector<int>();
    NB_WOOD.push_back(10);
    NB_WOOD.push_back(30);
    NB_WOOD.push_back(20);

    NB_ROCK = vector<int>();
    NB_ROCK.push_back(5);
    NB_ROCK.push_back(40);
    NB_ROCK.push_back(50);

    NB_FOOD = vector<int>();
    NB_FOOD.push_back(20);
    NB_FOOD.push_back(10);
    NB_FOOD.push_back(30);

    NB_VILLAGER = vector<int>();
    NB_VILLAGER.push_back(5);
    NB_VILLAGER.push_back(30);
    NB_VILLAGER.push_back(50);

    NB_FINAL_BUILDS = vector<int>();
    NB_FINAL_BUILDS.push_back(5);
    NB_FINAL_BUILDS.push_back(2);
    NB_FINAL_BUILDS.push_back(1);
}

Worlstate::~Worlstate()
{
    //dtor
}

Worlstate::IncrementValue(const int id){

    switch(id)
    {
    case 10:
        wood = wood + 1;
        cout << "Bois coupe" << endl;
        break;
    case 11:
        rock = rock + 1;
        cout << "Pierre minee" << endl;
        break;
    case 12:
        food = food  + 1;
        cout << "Nouriture préparee" << endl;
        break;
    case 13 :
        villager = villager  + 1;
        cout << "Villageois cree" << endl;
        break;
    case 0:
        house = house  + 1;
        DecreaseValue(RESSOURCES::WOOD, NB_WOOD[0]);
        DecreaseValue(RESSOURCES::ROCK, NB_ROCK[0]);
        DecreaseValue(RESSOURCES::FOOD, NB_FOOD[0]);
        cout << "Maison construite" << endl;
        break;
    case 1:
        religious_building = religious_building  + 1;
        DecreaseValue(RESSOURCES::WOOD, NB_WOOD[1]);
        DecreaseValue(RESSOURCES::ROCK, NB_ROCK[1]);
        DecreaseValue(RESSOURCES::FOOD, NB_FOOD[1]);
        cout << "Batiment religieux construit" << endl;
        break;
    case 2:
        city_hall = city_hall  + 1;
        DecreaseValue(RESSOURCES::WOOD, NB_WOOD[2]);
        DecreaseValue(RESSOURCES::ROCK, NB_ROCK[2]);
        DecreaseValue(RESSOURCES::FOOD, NB_FOOD[2]);
        cout << "Mairie construit" << endl;
        break;
    }
}

Worlstate::DecreaseValue(const int id, const int qty){

    switch(id)
    {
    case 10:
        wood = wood - qty;
        break;
    case 11:
        rock = rock - qty;
        break;
    case 12:
        food = food  - qty;
        break;
    case 13 :
        villager = villager  - qty;
        break;
    case 0:
        house = house  - qty;
        break;
    case 1:
        religious_building = religious_building  - qty;
        break;
    case 2:
        city_hall = city_hall  - qty;
        break;
    }
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
