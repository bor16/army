#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <set>
#include "../action/Action.h"
#include "../interface/IObserver.h"
#include "../interface/ISubject.h"
#include "../state/State.h"

class Unit : public ISubject {
    protected:
        State* state;
        Action* action;
        
        std::set<IObserver*>* observers;
        
        void ensureIsAlive();
        
    public:
        Unit(State* state, Action* action);
        virtual ~Unit();
        
        //state
        UnitClass getTitle() const;
        const Health getHealth() const;
        const int getDamage() const;
        virtual void takeImpact(Modifier& mod);
        virtual void takeMagDamage(Modifier& mod);
        
        //action
        virtual void attack(Unit& target, Unit& attacker);
        virtual void counterAttack(Unit& target, Unit& attacker);
        
        //IObserver
        void attach(IObserver* observer);
        void detach(IObserver* observer);
        void notify();
};

#endif //UNIT_H
