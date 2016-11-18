#ifndef WEREWOLFSTATE_H
#define WEREWOLFSTATE_H

#include <iostream>
#include "State.h"

class WerewolfState : public State {
    private:
        bool isWolf;
    public:
        WerewolfState(int maxHp, int physDmg);
        virtual ~WerewolfState();
        
        const bool wolf() const;
        
        void boost(int modifier);
        void shrink(int modifier);
};

#endif //WEREWOLFSTATE_H
