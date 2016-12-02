#include "Priest.h"

Priest::Priest(const std::string& name, UnitClass title, int maxHp, int damage, int maxMana) : Wizard(name, title, maxHp, damage, maxMana) {}

Priest::~Priest() {}
