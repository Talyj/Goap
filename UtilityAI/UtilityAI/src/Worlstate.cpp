#include "Worlstate.h"

Worlstate::Worlstate(const int nb_villagers, const int nb_woods, const int nb_houses)
{
    villagers = nb_villagers;
    woods = nb_woods;
    houses = nb_houses;
}

Worlstate::~Worlstate()
{
    //dtor
}
