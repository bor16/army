#include "State.h"

State::State(UnitClass title, Health health, int damage) : title(title), health(health), damage(damage) {}

State::~State() {}

UnitClass State::getTitle() const {
    return this->title;
}
const Health State::getHealth() const {
    return this->health;
}
const int State::getDamage() const {
    return this->damage;
}

void State::takeImpact(Modifier& mod) {
    this->health += mod;
}

void State::takeMagDamage(Modifier& mod) {
    this->takeImpact(mod);
}
