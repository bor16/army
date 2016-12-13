#include "State.h"

State::State(UnitClass title, int maxHp, int damage) : title(title), hp(maxHp), maxHp(maxHp), damage(damage) {}

State::~State() {}

const int State::getHp() const {
    return this->hp;
}
const int State::getMaxHp() const {
    return this->maxHp;
}
const int State::getDamage() const {
    return this->damage;
}
UnitClass State::getTitle() const {
    return this->title;
}

void State::calcHp(int points) {
    points += this->hp;
    if ( points < 0 ) {
        points = 0;
    }
    if ( points > this->maxHp ) {
        points = this->maxHp;
    }
    this->hp = points;
}

void State::setHp(int hp) {
    this->hp = hp;
}

void State::takeDamage(int damage) {
    this->calcHp(-damage);
}

void State::takeMagDamage(int damage) {
    this->takeDamage(damage);
}

void State::restoreHp(int points) {
    this->calcHp(points);
}
