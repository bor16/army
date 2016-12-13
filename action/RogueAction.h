#ifndef ROGUE_ACTION_H
#define ROGUE_ACTION_H

#include <iostream>
#include "Action.h"

class Unit;
class RogueAction : public Action {
    public:
        virtual ~RogueAction() {}
        
        void attack(Unit& target, Unit& attacker);
};

#endif //ROGUE_ACTION_H
