#ifndef DAMAGE_H
#define DAMAGE_H

#include <iostream>
#include "Modifier.h"

class Damage : public Modifier {
    protected:
        int points;
        
        int validatePoints(int value);
        
    public:
        Damage(int points=0);
        virtual ~Damage();
        
        const int getPoints() const;
        
        void setPoints(int value);
        
        void operator=(int value);
        void operator+=(int value);
        void operator-=(int value);
        void operator*=(int value);
        void operator/=(int value);
};

#endif //DAMAGE_H
