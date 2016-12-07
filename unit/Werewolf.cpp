#include "Werewolf.h"

Werewolf::Werewolf(Class title, int maxHp, int damage) : Soldier(title, maxHp, damage) {
    this->altState = new WolfState(title, maxHp, damage*2);
}

Werewolf::~Werewolf() {}

void Werewolf::shapeShift() {
    State* tmp = this->state;
    
    this->altState->setHp(this->getHp());
    this->state = this->altState;
    this->altState = tmp;
}
