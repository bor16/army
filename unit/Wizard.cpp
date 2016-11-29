#include "Wizard.h"

Wizard::Wizard(const std::string& name, const std::string& unitClass, int maxHp, int damage, int maxMana) : Soldier(name, unitClass, maxHp, damage) {
    this->state = new CasterState(name, unitClass, maxHp, damage, maxMana);
}

Wizard::~Wizard() {
    delete state;
}

const int Wizard::getMana() const {
    return state->getMana();
}
const int Wizard::getMaxMana() const {
    return state->getMaxMana();
}

void Wizard::reduceMana(int cost) {
    this->state->reduceMana(cost);
}

void Wizard::restoreMana(int points) {
    this->state->restoreMana(points);
}

void Wizard::cast(Unit& target, Spell& spell) {
    this->state->ensureIsAlive();
    
    this->reduceMana(spell.getCost());
    spell.action(target);
}
