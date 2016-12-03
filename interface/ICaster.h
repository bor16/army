#ifndef ICASTER_H
#define ICASTER_H

#include <iostream>
#include "../spell/SpellTitle.h"

class Unit;
class ICaster {
    public:
        virtual ~ICaster() {}
        
        virtual void cast(SpellTitle title, Unit& target) = 0;
};

#endif //ICASTER_H
