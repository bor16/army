#include "BerserkerState.h"

BerserkerState::BerserkerState(UnitClass title, Health health, int damage) : State(title, health, damage) {}

BerserkerState::~BerserkerState() {}

void BerserkerState::takeMagDamage(Modifier& mod) {
    std::cout << "F#!K you wizard!" << std::endl;
}
