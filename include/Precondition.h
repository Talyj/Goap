#ifndef PRECONDITION_H
#define PRECONDITION_H

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Precondition {
    private:
        string name;
        enum tag;
    public:
        Precondition();
        CompareRessources(enum );
        // CompareRessources(ressources a comparer, valeur a comparer, operateur a utiliser) true ou false

        virtual ~Precondition();

};

#endif // PRECONDITION_H
