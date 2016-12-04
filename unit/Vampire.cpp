#include "Vampire.h"

Vampire::Vampire(const std::string& name, UnitClass title, int maxHp, int damage) : Soldier(name, title, maxHp, damage) {}

Vampire::~Vampire() {}

void Vampire::attack(Unit& target) {
    int points = target.getHp();
    
    this->state->ensureIsAlive();
    
    target.takeDamage(this->getDamage());
    points -= target.getHp();
    this->restoreHp(points/2);
    
    if ( target.getHp() != 0 ) {
        target.counterAttack(*this);
    }
}

void Vampire::counterAttack(Unit& target) {
    int points = target.getHp();
    
    target.takeDamage(this->getDamage()/2);
    points -= target.getHp();
    this->restoreHp(points/2);
}
