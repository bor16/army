#ifndef NECROMANCER_ACTION_H
#define NECROMANCER_ACTION_H

#include <iostream>
#include "Action.h"

class Unit;
class NecromancerAction : public Action {
    public:
        virtual ~NecromancerAction() {}
        
        void attack(Unit& target, Unit& attacker);
        void counterAttack(Unit& target, Unit& attacker);
};

#endif //NECROMANCER_ACTION_H
