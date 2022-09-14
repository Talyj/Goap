#ifndef ACTION_H
#define ACTION_H

#include <vector>
#include <iostream>
#include <string>

#include "WorldState.h"
#include "Effect.h"
#include "Precondition.h"

using namespace std;

class Action {
    private:

        int action_count;
        vector<Effect*> effects;
        vector<Precondition*> preconditions;
    public:
        string name;
        Action();
        Action(string n);
        Action(string n, int ac);
        SetCount(int ac);
        AddEffect(string name, TAG tag, RESSOURCES res, int value, COMPARATOR c);
        GetName();
        GetCount();
        GetAllEffects(WorldState& ws);
        vector<Precondition*>GetAllPreconditions();
        AddPrecondition(string name, TAG tag, RESSOURCES res, int value, COMPARATOR c);

        vector<Effect*> GetEffects();
        vector<Action*> FindActionWithTagEffect(TAG tag, vector<Action*> allActions);
        void Process(WorldState& ws, vector<Action*> allActions, vector<Action*> *path);

        virtual ~Action();
};

#endif // ACTION_H
