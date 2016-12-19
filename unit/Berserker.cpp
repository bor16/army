#include "Berserker.h"

Berserker::Berserker(UnitClass title, int maxHp, int damage) : Soldier(title, maxHp, damage) {
    this->state = new BerserkerState(title, new Health(maxHp), damage);
}

Berserker::~Berserker() {
    delete state;
}

void Berserker::takeMagDamage(Modifier& mod) {
    this->state->takeMagDamage(mod);
}
