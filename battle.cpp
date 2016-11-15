#include <iostream>
#include "state/State.h"
#include "unit/Unit.h"
#include "unit/Soldier.h"

int main() {
    Soldier* s1 = new Soldier("John", "Soldier", 100, 10);
    Soldier* s2 = new Soldier("Smith", "Soldier", 100, 10);
    
    s1->attack(*s2);
    std::cout << *s1 << std::endl;
    std::cout << *s2 << std::endl;
    
    delete s1;
    delete s2;
    
    return 0;
}
