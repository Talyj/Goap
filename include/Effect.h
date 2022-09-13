#ifndef EFFECT_H
#define EFFECT_H

#include <WorldState.h>

#include <string>

using namespace std;
//class effect
// Fonction Apply(ressources a modifier, valeur a utiliser, operateur a utiliser); applique l'effet
// nom, enum tag

class Effect
{
    private:
        string name;
        RESSOURCES tag;

    public:
        Effect();
        Apply(RESSOURCES ressource, int value, COMPARATOR comparator);

        virtual ~Effect();
};

#endif // EFFECT_H
