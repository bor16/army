#include "Spell.h"

Spell::Spell(SpellTitle title, int power, int cost) : title(title), power(power), cost(cost) {}

Spell::~Spell() {}

SpellTitle Spell::getTitle() const {
    return this->title;
}
const int Spell::getPower() const {
    return this->power;
}
const int Spell::getCost() const {
    return this->cost;
}
