#ifndef STATE_H
#define STATE_H

#include <iostream>
#include "UnitClass.h"
#include "../interface/IFighterState.h"

class State : public IFighterState {
    protected:
        int hp;
        int maxHp;
        int damage;
        std::string name;
        UnitClass title;
        
        void calcHp(int points);
        
    public:
        State(const std::string& name, UnitClass title, int maxHp, int damage);
        virtual ~State();
        
        const int getHp() const;
        const int getMaxHp() const;
        const int getDamage() const;
        const std::string& getName() const;
        UnitClass getTitle() const;
        
        void setHp(int hp);
        
        void ensureIsAlive();
        
        virtual void takeDamage(int damage);
        virtual void takeMagDamage(int damage);
        virtual void restoreHp(int points);
};

std::ostream& operator<<(std::ostream& out, const State& state);

#endif //STATE_H
