#include "Berserker.h"

Berserker::Berserker(Class title, int maxHp, int damage) : Soldier(title, maxHp, damage) {
    this->state = new BerserkerState(title, maxHp, damage);
}

Berserker::~Berserker() {
    delete state;
}
