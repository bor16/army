#ifndef IFIGHTER_H
#define IFIGHTER_H

#include <iostream>

class Unit;
class IFighter {
    public:
        virtual ~IFighter() {}
        
        virtual void attack(Unit& target) = 0;
        virtual void counterAttack(Unit& target) = 0;
};

#endif //IFIGHTER_H
