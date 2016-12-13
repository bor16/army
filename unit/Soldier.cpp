#include "Soldier.h"

Soldier::Soldier(unitClass title, int maxHp, int damage) : Unit(new State(title, maxHp, damage)) {}

Soldier::~Soldier() {}
