#ifndef WEREWOLF_H
#define WEREWOLF_H

#include <iostream>
#include "Soldier.h"
#include "../state/WolfState.h"

class Werewolf : public Soldier {
    protected:
        State* altState;
        
    public:
        Werewolf(const std::string& name, UnitClass title=UnitClass::WEREWOLF, int maxHp=80, int damage=8);
        virtual ~Werewolf();
        
        void shapeShift();
};

#endif //WEREWOLF_H
