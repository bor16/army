#include "Berserker.h"

Berserker::Berserker(const std::string& name, const std::string& unitClass, int maxHp, int damage) : Soldier(name, unitClass, maxHp, damage) {
    this->state = new BerserkerState(name, unitClass, maxHp, damage);
}

Berserker::~Berserker() {
    delete state;
}
