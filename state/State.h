#ifndef STATE_H
#define STATE_H

#include <iostream>
#include "StateProperties.h"
#include "../exception/Exception.h"

class State {
    protected:
        UnitClass title;
        int hp;
        int maxHp;
        int damage;
        
        void calcHp(int points);
        
    public:
        State(UnitClass title, int maxHp, int damage);
        virtual ~State();
        
        UnitClass getTitle() const;
        /*virtual */const int getHp() const;
        const int getMaxHp() const;
        const int getDamage() const;
        
        void setHp(int hp);
        
        virtual void takeDamage(int damage);
        virtual void takeMagDamage(int damage);
        virtual void restoreHp(int points);
};

#endif //STATE_H
