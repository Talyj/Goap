#ifndef ACTION_H
#define ACTION_H
#include "Worlstate.h"
#include <string>

class Action
{
    public:
        Action(){};
        Action(const std::string res_name, const RESSOURCES type, const BUILDING other_type);
        virtual ~Action();
        float Update(const Worlstate ws, const RESSOURCES res);
        float Update(const Worlstate ws, const BUILDING bui);
        bool HaveEnoughResources(const Worlstate ws, BUILDING bui, RESSOURCES res);
        //Function apply
        //Function increment
        void IncrementValue(Worlstate ws, const int id, const bool increase_or_decrease);

        float utility_score;
        std::string name;
        RESSOURCES res_type;
        BUILDING bui_type;
    protected:

    private:
};

#endif // ACTION_H
