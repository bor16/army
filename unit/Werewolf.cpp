#include "Werewolf.h"

Werewolf::Werewolf(unitClass title, int maxHp, int damage) : Soldier(title, maxHp, damage) {
    this->state = new WerewolfState(title, maxHp, damage);
}

Werewolf::~Werewolf() {
    delete state;
}

const int Werewolf::getHp() const {
    return this->state->getHp();
}

void Werewolf::shapeShift() {
    this->ensureIsAlive();
    this->state->shapeShift();
}

void Werewolf::takeDamage(int damage) {
    this->state->takeDamage(damage);
}

void Werewolf::takeMagDamage(int damage) {
    this->state->takeMagDamage(damage);
}

void Werewolf::restoreHp(int points) {
    this->state->restoreHp(points);
}

