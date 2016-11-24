#include "Rogue.h"

Rogue::Rogue(const std::string& name, const std::string& unitClass, int maxHp, int damage) : Soldier(name, unitClass, maxHp, damage) {}

Rogue::~Rogue() {}

void Rogue::attack(Unit& enemy) {
    this->state->ensureIsAlive();
    
    enemy.takeDamage(this->getDamage());
}
