#ifndef WOLFSTATE_H
#define WOLFSTATE_H

#include <iostream>
#include "State.h"

class WolfState : public State {
    protected:
        void calcHp(double points);
        
    public:
        WolfState(const std::string& name, const std::string& unitClass, int maxHp, int damage);
        virtual ~WolfState();
        
        void takeDamage(int damage);
        void takeMagDamage(int damage);
};

#endif //WOLFSTATE_H
