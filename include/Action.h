#ifndef ACTION_H
#define ACTION_H

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Action {
    private:
        string name;
        int action_count;
        vector<string> effects;
        vector<string> preconditions;
    public:
        Action();
        Action(string n);
        Action(string n, int ac);
        SetCount(int ac);
        AddEffect(string e);
        GetName();
        GetCount();
        GetAllEffects();
        GetAllPreconditions();
        AddPrecondition(string p);
        virtual ~Action();
};

#endif // ACTION_H
