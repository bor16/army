#include "CasterState.h"

CasterState::CasterState(const std::string& name, const std::string& unitClass, int maxHp, int damage, int maxMana) : State(name, unitClass, maxHp, damage), mana(maxMana), maxMana(maxMana) {}

CasterState::~CasterState() {}

const int CasterState::getMana() const {
    return this->mana;
}
const int CasterState::getMaxMana() const {
    return this->maxMana;
}

void CasterState::calcMana(int points) {
    points += this->mana;
    if ( points < 0 ) {
        points = 0;
    }
    if ( points > this->maxMana ) {
        points > this->maxMana;
    }
    this->mana = points;
}

void CasterState::reduceMana(int cost) {
    ensureIsAlive();
    calcMana(-cost);
}

void CasterState::restoreMana(int points) {
    ensureIsAlive();
    calcMana(points);
}
