#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include "../state/State.h"
// #include "../state/WerewolfState.h"

class Unit {
    protected:
        State* state;
        
    public:
        Unit(const std::string& name, const std::string& unitClass, int maxHp, int damage);
        virtual ~Unit();
        
        const State& getState() const;
        const int getHp() const;
        const int getMaxHp() const;
        const int getDamage() const;
        const std::string& getName() const;
        const std::string& getUnitClass() const;
        
        // virtual void attack(Unit& enemy) = 0;
        // virtual void counterAttack(Unit& enemy) = 0;
};

std::ostream& operator<<(std::ostream& out, const Unit& unit);

#endif //UNIT_H
