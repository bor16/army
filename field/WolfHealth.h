#ifndef WOLFHEALTH_H
#define WOLFHEALTH_H

#include <iostream>
#include "Health.h"

class MagDamage;
class WolfHealth : public Health {
    public:
        WolfHealth(int limit);
        WolfHealth(int points, int limit);
        virtual ~WolfHealth();
        
        void operator+=(Modifier& mod);
        void operator+=(MagDamage& mod);
};

#endif //WOLFHEALTH_H
