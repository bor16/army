#ifndef STATE_H
#define STATE_H

#include <iostream>

class State {
    protected:
        int hp;
        int maxHp;
        int damage;
        std::string name;
        std::string unitClass;
        
        void calcHp(int points);
        
    public:
        State(const std::string& name, const std::string& unitClass, int maxHp, int damage);
        virtual ~State();
        
        const int getHp() const;
        const int getMaxHp() const;
        const int getDamage() const;
        const std::string& getName() const;
        const std::string& getUnitClass() const;
        
        void ensureIsAlive();
        
        virtual void takeDamage(int damage);
        virtual void restoreHp(int points);
};

std::ostream& operator<<(std::ostream& out, const State& state);

#endif //STATE_H
