#ifndef WEREWOLF_H
#define WEREWOLF_H

#include <iostream>
#include "Soldier.h"
#include "../state/WerewolfState.h"

class Werewolf : public Soldier {
    protected:
        WerewolfState* state;
        
    public:
        Werewolf(unitClass title=unitClass::WEREWOLF, int maxHp=(int)Hp::WEREWOLF, int damage=(int)Dmg::WEREWOLF);
        virtual ~Werewolf();
        
        const int getHp() const;
        
        void shapeShift();
        
        void takeDamage(int damage);
        void takeMagDamage(int damage);
        void restoreHp(int points);
};

#endif //WEREWOLF_H
