#include "CasterState.h"

CasterState::CasterState(UnitClass title, Health* health, int damage, Energy* energy) : State(title, health, damage), energy(energy) {}

CasterState::~CasterState() {
    delete energy;
}

const Energy& CasterState::getEnergy() const {
    return *(this->energy);
}

void CasterState::takeEnergyImpact(Modifier& mod) {
    *(this->energy) += mod;
}
