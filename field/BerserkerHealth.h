#ifndef BERSERKERHEALTH_H
#define BERSERKERHEALTH_H

#include <iostream>
#include "Health.h"

class MagDamage;
class BerserkerHealth : public Health {
    public:
        BerserkerHealth(int limit);
        BerserkerHealth(int points, int limit);
        virtual ~BerserkerHealth();
        
        void operator+=(const MagDamage& mod);
};

#endif //BERSERKERHEALTH_H
