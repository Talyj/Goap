#ifndef ACTION_H
#define ACTION_H
#include "Worlstate.h"

enum resource{
    bois,
    pierre,
    nourriture
};

class Action
{
    public:
        Action(){};
        Action(char actionName);
        virtual ~Action();
        virtual void Update(Worlstate ws){};
        float utility_score;
        char name;
    protected:

    private:
};

#endif // ACTION_H
