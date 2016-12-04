#ifndef IFIGHTERSTATE_H
#define IFIGHTERSTATE_H

#include <iostream>

class IFighterState {
    protected:
        virtual void calcHp(int points) = 0;
        
    public:
        virtual ~IFighterState() {}
        
        virtual void setHp(int hp) = 0;
        
        virtual void ensureIsAlive() = 0;
        
        virtual void takeDamage(int damage) = 0;
        virtual void takeMagDamage(int damage) = 0;
        virtual void restoreHp(int points) = 0;
};

#endif //IFIGHTERSTATE_H
