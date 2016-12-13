#include "Berserker.h"

Berserker::Berserker(UnitClass title, int maxHp, int damage) : Soldier(title, maxHp, damage) {
    this->state = new BerserkerState(title, maxHp, damage);
}

Berserker::~Berserker() {
    delete state;
}

void Berserker::takeMagDamage(int damage) {
    this->state->takeMagDamage(damage);
}
