#ifndef WORLSTATE_H
#define WORLSTATE_H
#include <string>
#include <list>

enum RESSOURCES : int{
    WOOD = 0,
    ROCK = 1,
    FOOD = 2,
};

enum BUILDING : int{
    HOUSE = 10,
    RELIGIOUS_BUILDING = 11,
    CITY_HALL = 12
};

class Worlstate
{
    public:
        Worlstate(const int nb_wood, const int nb_rock, const int nb_food, const int nb_house, const int nb_religious_building, const int nb_city_hall);
        virtual ~Worlstate();
        int operator[](const int index)const;


    int wood;
    int rock;
    int food;

    int house;
    int religious_building;
    int city_hall;

    private:
};

#endif // WORLSTATE_H
