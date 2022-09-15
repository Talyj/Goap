#ifndef ACTION_H
#define ACTION_H
#include "Worlstate.h"
#include <string>

class Action
{
    public:
        Action(){};
        Action(const std::string res_name/*, const RESSOURCES type*/);
        virtual ~Action();
        void Update(const Worlstate ws, const RESSOURCES res);
        void Update(const Worlstate ws, const BUILDING bui);

        float utility_score;
        std::string name;
    protected:

    private:
};

#endif // ACTION_H
