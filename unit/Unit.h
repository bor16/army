#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <set>
#include "../state/State.h"
#include "../interface/IFighter.h"
#include "../interface/IObserver.h"
#include "../interface/ISubject.h"

class Necromancer;
class Unit : public IFighter, public ISubject {
    protected:
        State* state;
        std::set<Necromancer*>* observers;
        
    public:
        Unit(State* state);
        virtual ~Unit();
        
        const State& getState() const;
        const int getHp() const;
        const int getMaxHp() const;
        const int getDamage() const;
        const std::string& getName() const;
        UnitClass getTitle() const;
        
        // IFighterState
        void takeDamage(int damage);
        void takeMagDamage(int damage);
        void restoreHp(int points);
        
        // ISubject
        void attach(Necromancer* observer);
        void detach(Necromancer* observer);
        void notify();
};

std::ostream& operator<<(std::ostream& out, const Unit& unit);

#endif //UNIT_H
