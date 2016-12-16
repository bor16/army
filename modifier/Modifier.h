#ifndef MODIFIER_H
#define MODIFIER_H

#include <iostream>

class Modifier {
        virtual int validatePoints(int value) = 0;
        
    public:
        virtual ~Modifier() {}
        
        virtual const int getPoints() const = 0;
        
        virtual void setPoints(int value) = 0;
        
        virtual void operator=(int value) = 0;
        virtual void operator+=(int value) = 0;
        virtual void operator-=(int value) = 0;
        virtual void operator*=(int value) = 0;
        virtual void operator/=(int value) = 0;
};

std::ostream& operator<<(std::ostream& out, const Modifier& modifier);

#endif //MODIFIER_H
