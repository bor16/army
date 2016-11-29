#ifndef SPELL_H
#define SPELL_H

#include <iostream>
#include "../unit/Unit.h"

class Spell {
    protected:
        int power;
        int cost;
        std::string title;
        
    public:
        Spell(int power, int cost, const std::string title);
        virtual ~Spell();
        
        const int getPower() const;
        const int getCost() const;
        const std::string getTitle() const;
        
        virtual void action(Unit& target) = 0;
};

#endif //SPELL_H
