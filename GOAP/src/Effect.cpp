#include "Effect.h"

Effect::Effect() {}

Effect::Effect(string name, TAG tag, RESSOURCES res, int value, COMPARATOR c) {
    this->name = name;
    this->tag = tag;
    this->res = res;
    this-> cond = value;
    this-> comp = c;
}

// Fonction qui permet d'appliquer l'effet
Effect::Apply(WorldState& ws) {
    switch(this->comp) {
        case 0: //HIGHER
            ws.SetNewValue(this->res, ws[this->res] + this->cond);
            break;
        case 1: //LOWER
            ws.SetNewValue(this->res, ws[this->res] - this->cond);
            break;
        default:
            cout << "Erreur: COMPARATOR inconnu." << endl;
            return false;
            break;
    }
}

TAG Effect::GetTag() const {
    return this->tag;
}

Effect::~Effect() {}
