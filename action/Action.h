#ifndef ACTION_H
#define ACTION_H

#include <iostream>

class Unit;
class Action {
    public:
        virtual ~Action() {}
        
        virtual void attack(Unit& target, Unit& attacker);
        virtual void counterAttack(Unit& target, Unit& attacker);
};

#endif //ACTION_H
