#include "Soldier.h"

Soldier::Soldier(const std::string& name, UnitClass title, int maxHp, int damage) : Unit(new State(name, title, maxHp, damage)) {}

Soldier::~Soldier() {}

void Soldier::attack(Unit& enemy) {
    this->state->ensureIsAlive();
    
    enemy.takeDamage(this->getDamage());
    
    if ( enemy.getHp() != 0 ) {
        enemy.counterAttack(*this);
    }
}

void Soldier::counterAttack(Unit& enemy) {
    enemy.takeDamage(this->getDamage()/2);
}
