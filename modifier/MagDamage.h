#ifndef MAGDAMAGE_H
#define MAGDAMAGE_H

#include <iostream> 
#include "Modifier.h"

class MagDamage : public Modifier {
    protected:
        int points;
        int type;
        
        int validatePoints(int value);
        
    public:
        MagDamage(int points=0);
        virtual ~MagDamage();
        
        const int getPoints() const;
        const int getType() const;
        
        void setPoints(int value);
        
        void operator=(int value);
        void operator+=(int value);
        void operator-=(int value);
        void operator*=(int value);
        void operator/=(int value);
};

std::ostream& operator<<(std::ostream& out, const MagDamage& mdmg);

#endif //MAGDAMAGE_H
