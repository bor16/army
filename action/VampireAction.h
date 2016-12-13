#ifndef VAMPIRE_ACTION_H
#define VAMPIRE_ACTION_H

#include <iostream>
#include "Action.h"

class Unit;
class VampireAction : public Action {
    public:
        virtual ~VampireAction() {}
        
        void attack(Unit& target, Unit& attacker);
        void counterAttack(Unit& target, Unit& attacker);
};

#endif //VAMPIRE_ACTION_H
