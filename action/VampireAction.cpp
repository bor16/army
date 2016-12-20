#include "VampireAction.h"
#include "../unit/Unit.h"
#include "../modifier/Damage.h"
#include "../modifier/Aid.h"
#include "../field/Health.h"

void VampireAction::attack(Unit& target, Unit& attacker) {
    Aid aid;
    Damage dmg;
    
    dmg = attacker.getDamage();
    aid = target.getHealth().getPoints();
    
    target.takeImpact(dmg);
    
    aid -= target.getHealth().getPoints();
    aid /= 2;
    
    attacker.takeImpact(aid);
    
    if ( target.getHealth() != 0 ) {
        target.counterAttack(attacker, target);
    }
}

void VampireAction::counterAttack(Unit& target, Unit& attacker) {
    Aid aid;
    Damage dmg;
    
    dmg = attacker.getDamage()/2;
    aid = target.getHealth().getPoints();
    
    target.takeImpact(dmg);
    
    aid -= target.getHealth().getPoints();
    aid /= 2;
    
    attacker.takeImpact(aid);
}
