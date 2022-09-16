#ifndef PRECONDITION_H
#define PRECONDITION_H

#include "WorldState.h"

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Precondition {
    private:
        RESSOURCES res;

        string name;
        TAG tag;
        int cond;
        int comp;
    public:
        Precondition();
        Precondition(string name, TAG tag, RESSOURCES res, int value, COMPARATOR c);
        TAG GetTag() const;
        string GetName() const;
        bool CompareRessources(WorldState ws);
        virtual ~Precondition();

};

#endif // PRECONDITION_H
