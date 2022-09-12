#include "Action.h"

Action::Action() {
}

Action::Action(std::string n) {
    this->name = n;
}

Action::Action(std::string n, int ac) {
    this->name = n;
    this->action_count = ac;
}

Action::SetCount(int ac) {
    this->action_count = ac;
}

Action::AddEffect(string e) {
    this->effects.push_back(e);
}

Action::AddPrecondition(string p) {
    this->preconditions.push_back(p);
}

Action::GetName() {
    if(this->name.empty()) {
        cout << "L'action n'a pas de nom." << endl;
    } else {
        cout << this->name << endl;
    }
}

Action::GetCount() {
    if(!this->action_count) {
        cout << "L'action n'a pas de cout." << endl;
    } else {
        cout << this->action_count << endl;
    }
}

Action::GetAllEffects() {
    if(this->effects.empty()) {
        cout << "L'action n'a pas d'effets." << endl;
    } else {
        for(int i = 0; i < this->effects.size(); i++) {
            cout << this->effects[i] << endl;
        }
    }
}

Action::GetAllPreconditions() {
    if(this->preconditions.empty()) {
        cout << "L'action n'a pas de preconditions." << endl;
    } else {
        for(int i = 0; i < this->preconditions.size(); i++) {
            cout << this->preconditions[i] << endl;
        }
    }
}

Action::~Action() {
    //dtor
}
