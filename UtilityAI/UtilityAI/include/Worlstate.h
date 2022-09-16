#ifndef WORLSTATE_H
#define WORLSTATE_H

#include <string>
#include <list>
#include <vector>

#define NB_FINAL_HOUSES 5
//#define NB_WOOD_HOUSE 10
//#define NB_ROCK_HOUSE 5
//#define NB_FOOD_HOUSE 5

#define NB_FINAL_RELIGIOUS_BUILDING 1
//#define NB_WOOD_RELIGIOUS_BUILDING 30
//#define NB_ROCK_RELIGIOUS_BUILDING 30
//#define NB_FOOD_RELIGIOUS_BUILDING 10

#define NB_FINAL_CITY_HALL 1
//#define NB_WOOD_CITY_HALL 20
//#define NB_ROCK_CITY_HALL 50
//#define NB_FOOD_CITY_HALL 20
using namespace std;

enum RESSOURCES : int{
    WOOD = 10,
    ROCK = 11,
    FOOD = 12,
    VILLAGER = 13,
};

enum BUILDING : int{
    HOUSE = 0,
    RELIGIOUS_BUILDING = 1,
    CITY_HALL = 2,
};

enum TAG : int{
    INCREASE_WOOD = 0,
    DECREASE_WOOD = 1,
    INCREASE_ROCK = 2,
    DECREASE_ROCK = 3,
    INCREASE_FOOD = 4,
    DECREASE_FOOD = 5,
};

class Worlstate
{
    public:
        Worlstate();
        Worlstate(const int nb_wood, const int nb_rock, const int nb_food, const int nb_house, const int nb_religious_building, const int nb_city_hall, const int nb_villager);
        virtual ~Worlstate();
        int operator[](const int index)const;

        vector<int> NB_WOOD;
        vector<int> NB_ROCK;
        vector<int> NB_FOOD;

        int wood;
        int rock;
        int food;
        int villager;

        int house;
        int religious_building;
        int city_hall;

    private:
};

#endif // WORLSTATE_H
