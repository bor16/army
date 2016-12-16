#include "Restore.h"
#include "../modifier/Aid.h"

Restore::Restore(SpellTitle title, int power, int cost) : Spell(title, power, cost) {}

Restore::~Restore() {}

void Restore::action(Unit& target, int modifier) {
    Aid aid;
    
    aid = this->getPower()/modifier;
    
    target.takeImpact(aid);
}
