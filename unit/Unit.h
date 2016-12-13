#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <set>
#include "../action/Action.h"
#include "../state/State.h"
#include "../interface/IObserver.h"
#include "../interface/ISubject.h"

class Unit : public ISubject {
    protected:
        State* state;
        Action* action;
        
        std::set<IObserver*>* observers;
        
        void ensureIsAlive();
        
    public:
        Unit(State* state);
        virtual ~Unit();
        
        //state
        unitClass getTitle() const;
        /*virtual */const int getHp() const;
        const int getMaxHp() const;
        const int getDamage() const;
        virtual void takeDamage(int damage);
        virtual void takeMagDamage(int damage);
        virtual void restoreHp(int points);
        
        //action
        virtual void attack(Unit& target, Unit& attacker);
        virtual void counterAttack(Unit& target, Unit& attacker);
        
        //IObserver
        void attach(IObserver* observer);
        void detach(IObserver* observer);
        void notify();
};

#endif //UNIT_H
