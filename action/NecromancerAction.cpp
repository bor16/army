#include "NecromancerAction.h"
#include "../unit/Unit.h"

void NecromancerAction::attack(Unit& target, Unit& attacker) {
    target.takeDamage(attacker.getDamage());
    // target.attach((IObserver*)(&attacker));
    target.attach(dynamic_cast<IObserver*>(&attacker));
    
    if ( target.getHp() != 0 ) {
        target.counterAttack(attacker, target);
    } else {
        target.notify();
    }
}

void NecromancerAction::counterAttack(Unit& target, Unit& attacker) {
    target.takeDamage(attacker.getDamage()/2);
    // target.attach((IObserver*)(&attacker));
    target.attach(dynamic_cast<IObserver*>(&attacker));
    
    if ( target.getHp() == 0 ) {
        target.notify();
    }
}
