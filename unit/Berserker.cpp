#include "Berserker.h"

Berserker::Berserker(const std::string& name, UnitClass title, int maxHp, int damage) : Soldier(name, title, maxHp, damage) {
    this->state = new BerserkerState(name, title, maxHp, damage);
}

Berserker::~Berserker() {
    delete state;
}
