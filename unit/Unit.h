#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <set>
#include "../state/State.h"
#include "../interface/i_unit/IObserver.h"
#include "../interface/i_unit/ISubject.h"

class Unit : public ISubject {
    protected:
        State* state;
        std::set<IObserver*>* observers;
        
    public:
        Unit(State* state);
        virtual ~Unit();
        
        const int getHp() const;
        const int getMaxHp() const;
        const int getDamage() const;
        Class getTitle() const;
        void takeDamage(int damage);
        void takeMagDamage(int damage);
        void restoreHp(int points);
        
        virtual void attack(Unit& target) = 0;
        virtual void counterAttack(Unit& target) = 0;
        
        void attach(IObserver* observer);
        void detach(IObserver* observer);
        void notify();
};

#endif //UNIT_H
