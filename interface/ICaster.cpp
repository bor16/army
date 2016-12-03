#include <iostream>

typedef enum {
    FLAME_STRIKE,
    HEAL
} SpellTitle;

class Unit;
class ICaster {
    public:
        virtual ~ICaster() {}
        
        virtual void cast(SpellTitle title, Unit& target) = 0;
};
