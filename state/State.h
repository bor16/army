#ifndef STATE_H
#define STATE_H

#include <iostream>
#include "StateProperties.h"
#include "../exception/Exception.h"

class State {
    protected:
        int hp;
        int maxHp;
        int damage;
        Class title;
        
        void calcHp(int points);
        
    public:
        State(Class title, int maxHp, int damage);
        virtual ~State();
        
        const int getHp() const;
        const int getMaxHp() const;
        const int getDamage() const;
        Class getTitle() const;
        
        void ensureIsAlive();
        void setHp(int hp);
        
        virtual void takeDamage(int damage);
        virtual void takeMagDamage(int damage);
        virtual void restoreHp(int points);
};

#endif //STATE_H
