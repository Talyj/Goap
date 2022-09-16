#ifndef WORLSTATE_H
#define WORLSTATE_H

#include "windows.h"
#include <string>
#include <list>
#include <vector>

#define NB_FINAL_HOUSES 5
#define NB_FINAL_RELIGIOUS_BUILDING 1
#define NB_FINAL_CITY_HALL 1

using namespace std;

enum RESSOURCES : int{
    WOOD = 10,
    ROCK = 11,
    FOOD = 12,
    VILLAGER = 13,
    NONE = 999
};

enum BUILDING : int{
    HOUSE = 0,
    RELIGIOUS_BUILDING = 1,
    CITY_HALL = 2,
    NONES = 999
};

class Worlstate
{
    public:
        Worlstate();
        Worlstate(const int nb_wood, const int nb_rock, const int nb_food, const int nb_house, const int nb_religious_building, const int nb_city_hall, const int nb_villager);
        virtual ~Worlstate();
        IncrementValue(const int id);
        DecreaseValue(const int id, const int qty);
        int operator[](const int index)const;

        vector<int> NB_WOOD;
        vector<int> NB_ROCK;
        vector<int> NB_FOOD;
        vector<int> NB_VILLAGER;

        vector<int> NB_FINAL_BUILDS;

        int wood;
        int rock;
        int food;
        int villager;

        int house;
        int religious_building;
        int city_hall;

        int wood_needed;
        int rock_needed;
        int food_needed;
        int villager_needed;

        int house_needed;
        int religious_building_needed;
        int city_hall_needed;

    private:
};

#endif // WORLSTATE_H
