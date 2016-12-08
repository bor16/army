#ifndef IDEFENSIVE_H
#define IDEFENSIVE_H

#include <iostream>
#include "../../unit/Unit.h"

class IDefensive {
    public:
        virtual ~IDefensive() {}
        
        virtual void assist(Unit& target) = 0;
};

#endif //IDEFENSIVE_H
