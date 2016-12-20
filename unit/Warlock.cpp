#include "Warlock.h"

Warlock::Warlock(UnitClass title, int maxHp, int damage, int maxMana) : Wizard(title, maxHp, damage, maxMana) {
    this->fiend = nullptr;
}

Warlock::~Warlock() {}

Demon& Warlock::getFiend() {
    if ( fiend.get() == nullptr ) {
        throw NoFiendException();
    }
    
    return *(fiend.get());
}

void Warlock::summonFiend() {
    this->fiend = std::unique_ptr<Demon>(new Demon());
}

void Warlock::dismissFiend() {
    fiend.reset();
}
