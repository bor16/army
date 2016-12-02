#include "Werewolf.h"

Werewolf::Werewolf(const std::string& name, UnitClass title, int maxHp, int damage) : Soldier(name, title, maxHp, damage) {
    this->altState = new WolfState(name, title, maxHp, damage*2);
}

Werewolf::~Werewolf() {}

void Werewolf::shapeShift() {
    State* tmp = this->state;
    
    this->altState->setHp(this->getHp());
    this->state = this->altState;
    this->altState = tmp;
}
