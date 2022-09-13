#ifndef WORLDSTATE_H
#define WORLDSTATE_H
#include <ostream>

enum RESSOURCES : int{
    WOOD = 0,
    ROCK = 1,
    VILLAGER = 2,
    HOUSE = 3
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



};



#endif // WORLDSTATE_H
