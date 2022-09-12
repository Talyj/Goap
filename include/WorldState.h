#ifndef WORLDSTATE_H
#define WORLDSTATE_H
#include <ostream>

enum ressources : int{
    wood_qty = 0,
    rock_qty = 1,
    villager_qty = 2,
    house_qty = 3
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
