#include "Soldier.h"

Soldier::Soldier(const std::string& name, UnitClass title, int maxHp, int damage) : Unit(new State(name, title, maxHp, damage)) {}

Soldier::~Soldier() {}

void Soldier::attack(Unit& target) {
    this->state->ensureIsAlive();
    
    target.takeDamage(this->getDamage());
    
    if ( target.getHp() != 0 ) {
        target.counterAttack(*this);
    }
}

void Soldier::counterAttack(Unit& target) {
    target.takeDamage(this->getDamage()/2);
}
