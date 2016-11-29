#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include "../state/State.h"
#include "../state/WolfState.h"

class Unit {
    protected:
        State* state;
        
    public:
        Unit(State* state);
        virtual ~Unit();
        
        const State& getState() const;
        const int getHp() const;
        const int getMaxHp() const;
        const int getDamage() const;
        const std::string& getName() const;
        const std::string& getUnitClass() const;
        
        void takeDamage(int damage);
        void takeMagDamage(int damage);
        void restoreHp(int points);
        
        virtual void attack(Unit& enemy) = 0;
        virtual void counterAttack(Unit& enemy) = 0;
};

std::ostream& operator<<(std::ostream& out, const Unit& unit);

#endif //UNIT_H
