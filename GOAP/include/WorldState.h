#ifndef WORLDSTATE_H
#define WORLDSTATE_H
#include <ostream>

enum RESSOURCES : int{
    WOOD = 0,
    ROCK = 1,
    VILLAGER = 2,
    HOUSE = 3
};

enum COMPARATOR : int{
    HIGHER = 0,
    LOWER = 1,
    EQUAL = 2,
    NOT_EQUAL = 3,
    HIGHER_OR_EQUAL = 4,
    LOWER_OR_EQUAL = 5
};

enum TAG : int {
    INCREASE_WOOD = 0,
    DECREASE_WOOD = 1,
    INCREASE_ROCK = 2,
    DECREASE_ROCK = 3,
    INCREASE_HOUSE = 4,
    DECREASE_HOUSE = 5,
    INCREASE_VILLAGER = 6,
    DECREASE_VILLAGER = 7
};

class WorldState
{
    public:
        WorldState(const int nb_villagers, const int nb_rocks, const int nb_woods, const int nb_houses);
        WorldState(){};
        virtual ~WorldState();
        int villagers;
        int rocks;
        int woods;
        int houses;

        int operator[](const int index)const;

        void SetNewValue(const int index, int value);
};



#endif // WORLDSTATE_H
