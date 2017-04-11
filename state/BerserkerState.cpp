#include "BerserkerState.h"

BerserkerState::BerserkerState(UnitClass title, int maxHp, int damage) : State(title, new Health(maxHp), damage) {
    this->health = std::unique_ptr<BerserkerHealth>(new BerserkerHealth(maxHp));
}

BerserkerState::~BerserkerState() {}

void BerserkerState::takeMagDamage(Modifier& mod) {
    std::cout << "F#!K you wizard!" << std::endl;
}
