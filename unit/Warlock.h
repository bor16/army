#ifndef WARLOCK_H
#define WARLOCK_H

#include <iostream>
#include "Wizard.h"
#include "Demon.h"

class Warlock : public Wizard {
    protected:
        std::unique_ptr<Demon> fiend;
    
    public:
        Warlock(UnitClass title=UnitClass::WARLOCK, int maxHp=(int)Hp::WARLOCK, int damage=(int)Dmg::WARLOCK, int maxMana=(int)Mana::WARLOCK);
        virtual ~Warlock();
        
        Demon& getFiend();
        
        void summonFiend();
        void dismissFiend();
};

#endif //WARLOCK_H
