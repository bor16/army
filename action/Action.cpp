#include "Action.h"
#include "../unit/Unit.h"

void Action::attack(Unit& target, Unit& attacker) {
    target.takeDamage(attacker.getDamage());
    
    if ( target.getHp() != 0 ) {
        target.counterAttack(attacker, target);
    }
}

void Action::counterAttack(Unit& target, Unit& attacker) {
    target.takeDamage(attacker.getDamage()/2);
}
