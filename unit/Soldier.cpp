#include "Soldier.h"

Soldier::Soldier(const std::string& name, const std::string& unitClass, int maxHp, int damage) : Unit(name, unitClass, maxHp, damage) {}

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
