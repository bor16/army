#ifndef NECROMANCER_H
#define NECROMANCER_H

#include <iostream>
#include "Wizard.h"
#include "../interface/i_unit/IObserver.h"

class Necromancer : public Wizard, public IObserver {
    protected:
        std::set<Unit*>* subjects;
        
    public:
        Necromancer(Class title=Class::NECROMANCER, int maxHp=static_cast<int>(Hp::NECROMANCER), int damage=static_cast<int>(Dmg::NECROMANCER), int maxMana=static_cast<int>(Mana::NECROMANCER));
        virtual ~Necromancer();
        
        void attack(Unit& target);
        void counterAttack(Unit& target);
        
        void update();
        void attachSubject(Unit* subject);
        void detachSubject(Unit* subject);
        void notifySubject();
};

#endif //NECROMANCER_H
