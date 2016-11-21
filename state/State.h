#ifndef STATE_H
#define STATE_H

#include <iostream>

class State {
    protected:
        int hp;
        int maxHp;
        int damage;
        
        void calcHp(int points);
        
    public:
        State(int maxHp, int damage);
        virtual ~State();
        
        const int getHp() const;
        const int getMaxHp() const;
        const int getDamage() const;
        
        void ensureIsAlive();
        
        virtual void takeDamage(int damage);
        virtual void restoreHp(int points);
};

std::ostream& operator<<(std::ostream& out, const State& state);

#endif //STATE_H
