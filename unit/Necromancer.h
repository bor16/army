#ifndef NECROMANCER_H
#define NECROMANCER_H

#include <iostream>
#include "Wizard.h"

class Necromancer : public Wizard, public IObserver {
    protected:
        std::set<Unit*>* subjects;
        
    public:
        Necromancer(const std::string& name, UnitClass title=UnitClass::NECROMANCER, int maxHp=80, int damage=5, int maxMana=100);
        virtual ~Necromancer();
        
        void attack(Unit& target);
        void counterAttack(Unit& target);
        
        void update();
        void attachSubject(Unit* subject);
        void detachSubject(Unit* subject);
        void notifySubject();
};

#endif //NECROMANCER_H
