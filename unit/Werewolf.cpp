#include "Werewolf.h"

Werewolf::Werewolf(const std::string& name, const std::string& unitClass, int maxHp, int damage) : Soldier(name, unitClass, maxHp, damage) {
    this->altState = new WolfState(name, unitClass, maxHp, damage);
}

Werewolf::~Werewolf() {}

void Werewolf::shapeShift() {
    State* tmp = this->state;
    
    this->altState->setHp(this->getHp());
    this->state = this->altState;
    this->altState = tmp;
}

void Werewolf::attack(Unit& enemy) {
    this->state->ensureIsAlive();
    
    enemy.takeDamage(this->getDamage()*2);
    
    if ( enemy.getHp() != 0 ) {
        enemy.counterAttack(*this);
    }
}

void Werewolf::counterAttack(Unit& enemy) {
    enemy.takeDamage(this->getDamage());
}
