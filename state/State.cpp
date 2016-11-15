#include "State.h"

State::State(int maxHp, int physDmg) : hp(maxHp), maxHp(maxHp), physDmg(physDmg), isWerewolf(false), isVampire(false) {
    std::cout << "***State***" << std::endl;
}

State::~State() {
    std::cout << "~~~State~~~" << std::endl;
}

void State::setHp(int points) {
    this->hp = points;
}

const int State::getHp() const {
    return this->hp;
}
const int State::getMaxHp() const {
    return this->maxHp;
}
const int State::getPhysDmg() const {
    return this->physDmg;
}
const bool State::werewolf() const {
    return isWerewolf;
}
const bool State::vampire() const {
    return isVampire;
}

void State::becomeWerewolf() {
    this->isWerewolf = true;
}
void State::becomeVampire() {
    this->isVampire = true;
}

std::ostream& operator<<(std::ostream& out, const State& state) {
    out << "hp(" << state.getHp() << "/" << state.getMaxHp() << "), ";
    out << "physDmg(" << state.getPhysDmg() << ")";
    
    return out;
}
