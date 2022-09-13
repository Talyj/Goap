#include "Precondition.h"

Precondition::Precondition() {

}

Precondition::Precondition(string name, TAG tag, RESSOURCES res, int value, COMPARATOR c) {
    this->name = name;
    this->tag = tag;
    this->res = res;
    this-> cond = value;
    this-> comp = c;
}

bool Precondition::CompareRessources(WorldState ws) {
    switch(this->comp) {
        case 0: //HIGHER
            return ws[this->res] > this->cond;
            break;
        case 1: //LOWER
            return ws[this->res] < this->cond;
            break;
        case 2: //EQUAL
            return ws[this->res] == this->cond;
            break;
        case 3: //NOT_EQUAL
            return ws[this->res] != this->cond;
            break;
        case 4: //HIGHER_OR_EQUAL
            return ws[this->res] >= this->cond;
            break;
        case 5: //LOWER_OR_EQUAL
            return ws[this->res] <= this->cond;
            break;
        default:
            cout << "Erreur: COMPARATOR inconnu." << endl;
            return false;
            break;
    }
}

Precondition::~Precondition() {
    //dtor
}
