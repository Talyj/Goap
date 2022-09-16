#ifndef EFFECT_H
#define EFFECT_H

#include <WorldState.h>

#include <string>
#include <iostream>

using namespace std;

class Effect {
    private:
        RESSOURCES res;
        TAG tag;

        string name;
        int cond;
        int comp;
    public:
        Effect();
        Effect(string name, TAG tag, RESSOURCES res, int value, COMPARATOR c);
        TAG GetTag() const;
        Apply(WorldState& ws);

        virtual ~Effect();
};

#endif // EFFECT_H
