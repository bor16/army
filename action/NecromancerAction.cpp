#include "NecromancerAction.h"
#include "../unit/Unit.h"
#include "../modifier/Damage.h"
#include "../field/Health.h"

void NecromancerAction::attack(Unit& target, Unit& attacker) {
    Damage dmg;
    
    dmg = attacker.getDamage();
    
    target.takeImpact(dmg);
    // target.attach((IObserver*)(&attacker));
    target.attach(dynamic_cast<IObserver*>(&attacker));
    
    if ( target.getHealth() != 0 ) {
        target.counterAttack(attacker, target);
    } else {
        target.notify();
    }
}

void NecromancerAction::counterAttack(Unit& target, Unit& attacker) {
    Damage dmg;
    
    dmg = attacker.getDamage();
    
    target.takeImpact(dmg);
    // target.attach((IObserver*)(&attacker));
    target.attach(dynamic_cast<IObserver*>(&attacker));
    
    if ( target.getHealth() == 0 ) {
        target.notify();
    }
}
