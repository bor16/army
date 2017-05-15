#include "Berserker.h"

Berserker::Berserker(UnitClass title, int maxHp, int damage) : Soldier(title, maxHp, damage) {
    this->state = std::unique_ptr<BerserkerState>(new BerserkerState(title, maxHp, damage));
}

Berserker::~Berserker() {}

const Health& Berserker::getHealth() const {
    return this->state->getHealth();
}

void Berserker::takeImpact(Modifier& mod) {
    this->state->takeImpact(mod);
}

void Berserker::takeImpact(MagDamage& mod) {
    this->state->takeImpact(mod);
}

void Berserker::takeMagDamage(Modifier& mod) {
    this->state->takeMagDamage(mod);
}
