#ifndef WEREWOLF_STATE_H
#define WEREWOLF_STATE_H

#include <iostream>
#include "State.h"
#include "WolfState.h"
#include "../modifier/MagDamage.h"

class WerewolfState : public State {
    protected:
        std::unique_ptr<State> active;
        std::unique_ptr<State> alternative;
        
    public:
        WerewolfState(UnitClass title, int maxHp, int damage);
        virtual ~WerewolfState();
        
        const Health getHealth() const;
        
        void shapeShift();
        
        void takeImpact(Modifier& mod);
        void takeImpact(MagDamage& mod);
        void takeMagDamage(Modifier& mod);
};

#endif //WEREWOLF_STATE_H
