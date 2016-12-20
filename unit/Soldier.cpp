#include "Soldier.h"

Soldier::Soldier(UnitClass title, int maxHp, int damage) : Unit(new State(title, new Health(maxHp), damage), new Action()) {}

Soldier::~Soldier() {}
