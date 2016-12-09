#ifndef NECROMANCER_H
#define NECROMANCER_H

#include <iostream>
#include "Wizard.h"

class Necromancer : public Wizard, public IObserver {
    protected:
        std::set<ISubject*>* subjects;
        
    public:
        Necromancer(Class title=Class::NECROMANCER, int maxHp=(int)Hp::NECROMANCER, int damage=(int)Dmg::NECROMANCER, int maxMana=(int)Mana::NECROMANCER);
        virtual ~Necromancer();
        
        void attack(Unit& target);
        void counterAttack(Unit& target);
        
        void update();
        void attachSubject(ISubject* subject);
        void detachSubject(ISubject* subject);
        void notifySubject();
};

#endif //NECROMANCER_H
