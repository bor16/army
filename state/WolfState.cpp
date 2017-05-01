#include "WolfState.h"

WolfState::WolfState(UnitClass title, Health* health, int damage) : State(title, health, damage) {}

WolfState::~WolfState() {}

void WolfState::takeImpact(Modifier& mod) {
    *(this->health) += mod;
}

void WolfState::takeImpact(MagDamage& mod) {
    *(this->health) += mod;
}

void WolfState::takeMagDamage(Modifier& mod) {
    mod *= 2;
    
    *(this->health) += mod;
}
