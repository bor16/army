#ifndef NECROMANCER_H
#define NECROMANCER_H

#include <iostream>
#include "Wizard.h"
#include "../action/NecromancerAction.h"

class Necromancer : public Wizard, public IObserver {
    protected:
        std::unique_ptr<NecromancerAction> action;
        std::set<ISubject*>* subjects;
        
    public:
        Necromancer(UnitClass title=UnitClass::NECROMANCER, int maxHp=(int)Hp::NECROMANCER, int damage=(int)Dmg::NECROMANCER, int maxMana=(int)Mana::NECROMANCER);
        virtual ~Necromancer();
        
        void attack(Unit& target, Unit& attacker);
        void counterAttack(Unit& target, Unit& attacker);
        
        void update();
        void attachSubject(ISubject* subject);
        void detachSubject(ISubject* subject);
        void notifySubject();
};

#endif //NECROMANCER_H
