#include "Soldier.h"

Soldier::Soldier(UnitClass title, int maxHp, int damage) : Unit(new State(title, maxHp, damage)) {}

Soldier::~Soldier() {}
