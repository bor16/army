#include "Berserker.h"

Berserker::Berserker(UnitClass title, int maxHp, int damage) : Soldier(title, maxHp, damage) {
    this->state = std::unique_ptr<BerserkerState>(new BerserkerState(title, new Health(maxHp), damage));
}

Berserker::~Berserker() {}

void Berserker::takeMagDamage(Modifier& mod) {
    this->state->takeMagDamage(mod);
}
