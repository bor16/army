#include "RogueAction.h"
#include "../unit/Unit.h"
#include "../modifier/Damage.h"
#include "../field/Health.h"

void RogueAction::attack(Unit& target, Unit& attacker) {
    Damage dmg;
    
    dmg = attacker.getDamage();
    
    target.takeImpact(dmg);
}
