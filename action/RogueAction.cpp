#include "RogueAction.h"
#include "../unit/Unit.h"

void RogueAction::attack(Unit& target, Unit& attacker) {
    target.takeDamage(attacker.getDamage());
}
