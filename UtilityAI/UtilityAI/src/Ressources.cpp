#include "Ressources.h"

//Called gather
Ressources::Ressources(char resName)
{
    name = resName;
}

Ressources::Ressources()
{

}

Ressources::~Ressources()
{
    //dtor
}

void Ressources::Update(Worlstate ws, resource res)
{
    int time_to_gather = 0;
    int resource_weight = 0;
    int resource_qty = 0;

    switch(res){

    }
    utility_score = 0;
}
