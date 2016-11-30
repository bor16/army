#include "Werewolf.h"

Werewolf::Werewolf(const std::string& name, const std::string& unitClass, int maxHp, int damage) : Soldier(name, unitClass, maxHp, damage) {
    this->altState = new WolfState(name, unitClass, maxHp, damage*2);
}

Werewolf::~Werewolf() {}

void Werewolf::shapeShift() {
    State* tmp = this->state;
    
    this->altState->setHp(this->getHp());
    this->state = this->altState;
    this->altState = tmp;
}
