#include "Werewolf.h"

Werewolf::Werewolf(UnitClass title, int maxHp, int damage) : Soldier(title, maxHp, damage) {
    this->state = std::unique_ptr<WerewolfState>(new WerewolfState(title, maxHp, damage));
}

Werewolf::~Werewolf() {}

const Health Werewolf::getHealth() const {
    return this->state->getHealth();
}

void Werewolf::shapeShift() {
    this->ensureIsAlive();
    this->state->shapeShift();
}

void Werewolf::takeImpact(Modifier& mod) {
    this->state->takeImpact(mod);
}

void Werewolf::takeImpact(MagDamage& mod) {
    this->state->takeImpact(mod);
}

void Werewolf::takeMagDamage(Modifier& mod) {
    this->state->takeMagDamage(mod);
}
