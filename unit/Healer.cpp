#include "Healer.h"

Healer::Healer(const std::string& name, UnitClass title, int maxHp, int damage, int maxMana) : Wizard(name, title, maxHp, damage, maxMana) {}

Healer::~Healer() {}
