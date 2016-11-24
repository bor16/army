#ifndef WEREWOLFSTATE_H
#define WEREWOLFSTATE_H

#include <iostream>
#include "State.h"

class WerewolfState : public State {
    private:
        bool isWolf;
        
    public:
        WerewolfState(const std::string& name, const std::string& unitClass, int maxHp, int damage, bool isWolf=false);
        virtual ~WerewolfState();
        
        const bool wolf() const;
        
        void boost(int modifier);
        void shrink(int modifier);
};

#endif //WEREWOLFSTATE_H
