#ifndef WEREWOLF_H
#define WEREWOLF_H

#include <iostream>
#include "Soldier.h"

class Werewolf : public Soldier {
    protected:
        State* altState;
        
    public:
        Werewolf(const std::string& name, const std::string& unitClass="Werewolf", int maxHp=80, int damage=8);
        virtual ~Werewolf();
        
        void shapeShift();
        
        void attack(Unit& enemy);
        void counterAttack(Unit& enemy);
};

#endif //WEREWOLF_H
