#include "Werewolf.h"

Werewolf::Werewolf(const std::string& name, const std::string& unitClass, int maxHp, int damage) : Soldier(name, unitClass, maxHp, damage), state(new WerewolfState(name, unitClass, maxHp, damage)) {}

Werewolf::~Werewolf() {
    delete state;
}

const bool Werewolf::wolf() const {
    return state->wolf();
}

void Werewolf::shapeShift() {
    if ( this->wolf() ) {
        state->shrink(2);
    } else {
        state->boost(2);
    }
}
