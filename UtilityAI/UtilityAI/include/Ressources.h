#ifndef RESSOURCES_H
#define RESSOURCES_H
#include "Action.h"


class Ressources : public Action //Called gather
{
    public:
        Ressources();
        Ressources(char resName);
        virtual void Update(Worlstate ws, resource res);
        virtual ~Ressources();

    protected:

    private:
};

#endif // RESSOURCES_H
