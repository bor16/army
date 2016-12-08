#ifndef IOFFENSIVE_H
#define IOFFENSIVE_H

#include <iostream>
#include "../../unit/Unit.h"

class IOffensive {
    public:
        virtual ~IOffensive() {}
        
        virtual void harm(Unit& target) = 0;
};

#endif //IOFFENSIVE_H
