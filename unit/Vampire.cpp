#include "Vampire.h"

Vampire::Vampire(const std::string& name, UnitClass title, int maxHp, int damage) : Soldier(name, title, maxHp, damage) {}

Vampire::~Vampire() {}

void Vampire::attack(Unit& enemy) {
    int points = enemy.getHp();
    
    this->state->ensureIsAlive();
    
    enemy.takeDamage(this->getDamage());
    points -= enemy.getHp();
    this->restoreHp(points/2);
    
    if ( enemy.getHp() != 0 ) {
        enemy.counterAttack(*this);
    }
}

void Vampire::counterAttack(Unit& enemy) {
    int points = enemy.getHp();
    
    enemy.takeDamage(this->getDamage()/2);
    points -= enemy.getHp();
    this->restoreHp(points/2);
}
