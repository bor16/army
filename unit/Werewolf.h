#ifndef WEREWOLF_H
#define WEREWOLF_H

#include <iostream>
#include "Soldier.h"
#include "../state/WolfState.h"

class Werewolf : public Soldier {
    protected:
        State* altState;
        
    public:
        Werewolf(Class title=Class::WEREWOLF, int maxHp=(int)Hp::WEREWOLF, int damage=(int)Dmg::WEREWOLF);
        virtual ~Werewolf();
        
        void shapeShift();
};

#endif //WEREWOLF_H
