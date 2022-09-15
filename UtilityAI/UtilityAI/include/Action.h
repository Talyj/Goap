#ifndef ACTION_H
#define ACTION_H
#include "Worlstate.h"
#include <string>

class Action
{
    public:
        Action(){};
        Action(const std::string res_name, const RESSOURCES type);
        Action(const std::string res_name, const BUILDING type);
        virtual ~Action();
        void Update(const Worlstate* ws, const RESSOURCES res);
        float Update(const Worlstate* ws, const BUILDING bui);
        bool HaveEnoughResources(const Worlstate* ws, BUILDING bui);

        float utility_score;
        std::string name;
        RESSOURCES res_type;
        BUILDING bui_type;
    protected:

    private:
};

#endif // ACTION_H
