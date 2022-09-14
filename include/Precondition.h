#ifndef PRECONDITION_H
#define PRECONDITION_H

#include <vector>
#include <iostream>
#include <string>
#include "WorldState.h"

using namespace std;

class Precondition {
    private:


        RESSOURCES res;
        int cond;
        int comp;
    public:
        string name;
        TAG tag;
        Precondition();
        Precondition(string name, TAG tag, RESSOURCES res, int value, COMPARATOR c);
        bool CompareRessources(WorldState ws);
        virtual ~Precondition();

};

#endif // PRECONDITION_H
