#ifndef ENERGY_H
#define ENERGY_H

#include <iostream>
#include "Health.h"

class Energy : public Health {
    public:
        Energy(int limit);
        Energy(int points, int limit);
        virtual ~Energy();
};

#endif //ENERGY_H
