#ifndef WORLSTATE_H
#define WORLSTATE_H

#include <string>
#include <list>
#include <vector>

#define NB_FINAL_HOUSES 5
#define NB_WOOD_HOUSE 10
#define NB_ROCK_HOUSE 5
#define NB_FOOD_HOUSE 5

#define NB_FINAL_RELIGIOUS_BUILDING 1
#define NB_WOOD_RELIGIOUS_BUILDING 30
#define NB_ROCK_RELIGIOUS_BUILDING 30
#define NB_FOOD_RELIGIOUS_BUILDING 10

#define NB_FINAL_CITY_HALL 1
#define NB_WOOD_CITY_HALL 20
#define NB_ROCK_CITY_HALL 50
#define NB_FOOD_CITY_HALL 20


enum RESSOURCES : int{
    WOOD = 0,
    ROCK = 1,
    FOOD = 2,
    VILLAGER = 3,
};

enum BUILDING : int{
    HOUSE = 10,
    RELIGIOUS_BUILDING = 11,
    CITY_HALL = 12,
};

const char* NB_WOOD[] =
{
    "10", //HOUSE
    "30", //RELIGIOUS_BUILD
    "20"  // CITY_HALL
};

class Worlstate
{
    public:
        Worlstate();
        Worlstate(const int nb_wood, const int nb_rock, const int nb_food, const int nb_house, const int nb_religious_building, const int nb_city_hall, const int nb_villager);
        virtual ~Worlstate();
        int operator[](const int index)const;


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
