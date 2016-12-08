#ifndef NECROMANCER_H
#define NECROMANCER_H

#include <iostream>
#include "Wizard.h"

class Necromancer : public Wizard, public IObserver {
    protected:
        std::set<ISubject*>* subjects;
        
    public:
        Necromancer(Class title=Class::NECROMANCER, int maxHp=static_cast<int>(Hp::NECROMANCER), int damage=static_cast<int>(Dmg::NECROMANCER), int maxMana=static_cast<int>(Mana::NECROMANCER));
        virtual ~Necromancer();
        
        void attack(Unit& target);
        void counterAttack(Unit& target);
        
        void update();
        void attachSubject(ISubject* subject);
        void detachSubject(ISubject* subject);
        void notifySubject();
};

#endif //NECROMANCER_H
