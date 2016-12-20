#include "WolfState.h"

WolfState::WolfState(UnitClass title, Health* health, int damage) : State(title, health, damage) {}

WolfState::~WolfState() {}

void WolfState::takeMagDamage(Modifier& mod) {
    mod *= 2;
    
    *(this->health) += mod;
}
