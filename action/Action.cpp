#include "Action.h"
#include "../unit/Unit.h"
#include "../modifier/Damage.h"
#include "../field/Health.h"

void Action::attack(Unit& target, Unit& attacker) {
    Damage dmg;
    
    dmg = attacker.getDamage();
    
    target.takeImpact(dmg);
    
    if ( target.getHealth() != 0 ) {
        target.counterAttack(attacker, target);
    }
}

void Action::counterAttack(Unit& target, Unit& attacker) {
    Damage dmg;
    
    dmg = attacker.getDamage()/2;
    
    target.takeImpact(dmg);
}
