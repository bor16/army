#ifndef AID_H
#define AID_H

#include <iostream>
#include "Modifier.h"

class Aid : public Modifier {
    protected:
        int points;
        
        int validatePoints(int value);
        
    public:
        Aid(int points=0);
        virtual ~Aid();
        
        const int getPoints() const;
        
        void setPoints(int value);
        
        void operator=(int value);
        void operator+=(int value);
        void operator-=(int value);
        void operator*=(int value);
        void operator/=(int value);
};

#endif //AID_H
