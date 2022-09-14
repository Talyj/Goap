#ifndef WORLSTATE_H
#define WORLSTATE_H

class Worlstate
{
    public:
        Worlstate(const int nb_villagers, const int nb_woods, const int nb_houses);
        virtual ~Worlstate();

    int villagers;
    int woods;
    int houses;

    private:
};

#endif // WORLSTATE_H
