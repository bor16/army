#ifndef ICASTERSTATE_H
#define ICASTERSTATE_H

#include <iostream>

class ICasterState {
    protected:
        virtual void calcMana(int points) = 0;
        
    public:
        virtual ~ICasterState() {}
        
        virtual void reduceMana(int cost) = 0;
        virtual void restoreMana(int points) = 0;
};

#endif //ICASTERSTATE_H
