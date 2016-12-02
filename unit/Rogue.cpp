#include "Rogue.h"

Rogue::Rogue(const std::string& name, UnitClass title, int maxHp, int damage) : Soldier(name, title, maxHp, damage) {}

Rogue::~Rogue() {}

void Rogue::attack(Unit& enemy) {
    this->state->ensureIsAlive();
    
    enemy.takeDamage(this->getDamage());
}
