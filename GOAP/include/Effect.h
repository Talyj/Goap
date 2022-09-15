#ifndef EFFECT_H
#define EFFECT_H

#include <WorldState.h>

#include <string>
#include <iostream>

using namespace std;
//class effect
// Fonction Apply(ressources a modifier, valeur a utiliser, operateur a utiliser); applique l'effet
// nom, enum tag

class Effect
{
    private:
        string name;

        RESSOURCES res;
        int cond;
        int comp;

    public:
        TAG tag;
        Effect();
        Effect(string name, TAG tag, RESSOURCES res, int value, COMPARATOR c);
        Apply(WorldState& ws);

        virtual ~Effect();
};

#endif // EFFECT_H
