#ifndef STATE_H
#define STATE_H

#include <iostream>

class State {
    protected:
        int hp;
        int maxHp;
        int physDmg;
        
        bool isWerewolf;
        bool isVampire;
        
    public:
        State(int maxHp, int physDmg);
        virtual ~State();
        
        void setHp(int points);
        
        const int getHp() const;
        const int getMaxHp() const;
        const int getPhysDmg() const;
        const bool werewolf() const;
        const bool vampire() const;
        
        void becomeWerewolf();
        void becomeVampire();
};

std::ostream& operator<<(std::ostream& out, const State& state);

#endif //STATE_H
