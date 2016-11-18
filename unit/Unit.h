#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include "../state/State.h"
#include "../state/WerewolfState.h"

class Unit {
    protected:
        State* state;
        std::string name;
        std::string unitClass;
        
        void setHp(int physPts, int magPts);
        
    public:
        Unit(const std::string& name, const std::string& unitClass, int maxHp, int physDmg);
        virtual ~Unit();
        
        const State& getState() const;
        const int getHp() const;
        const int getMaxHp() const;
        const int getPhysDmg() const;
        const std::string& getName() const;
        const std::string& getUnitClass() const;
        
        const bool dead() const;
        const bool werewolf() const;
        const bool vampire() const;
        
        void becomeWerewolf();
        void becomeVampire();
        
        virtual void attack(Unit& enemy) = 0;
        virtual void counterAttack(Unit& enemy) = 0;
        virtual void takeDamage(int physDmg, int magDmg) = 0;
        virtual void restoreHp(int physPts, int magPts) = 0;
};

std::ostream& operator<<(std::ostream& out, const Unit& unit);

#endif //UNIT_H
