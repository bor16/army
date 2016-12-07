#include "Soldier.h"

Soldier::Soldier(Class title, int maxHp, int damage) : Unit(new State(title, maxHp, damage)) {}

Soldier::~Soldier() {}

void Soldier::attack(Unit& target) {
    Unit::attack(target);
}

void Soldier::counterAttack(Unit& target) {
    Unit::counterAttack(target);
}
