#include "Spell.h"

Spell::Spell(int power, int cost, SpellTitle title) : power(power), cost(cost), title(title) {}

Spell::~Spell() {}

const int Spell::getPower() const {
    return this->power;
}
const int Spell::getCost() const {
    return this->cost;
}
SpellTitle Spell::getTitle() const {
    return this->title;
}
