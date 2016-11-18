#ifndef WEREWOLF_H
#define WEREWOLF_H

#include <iostream>
#include "Soldier.h"

class Werewolf : public Soldier {
    private:
        WerewolfState* state;
        
        void shapeShift();
        
    public:
        Werewolf(const std::string& name, const std::string& unitClass="Werewolf", int maxHp=80, int physDmg=8);
        virtual ~Werewolf();
        
        const bool wolf() const;
};

#endif //WEREWOLF_H
