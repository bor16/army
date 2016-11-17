#include "../state/State.h"
#include "../unit/Unit.h"
#include "../unit/Soldier.h"
#include "catch.hpp"

TEST_CASE("test Unit", "[Unit]") {
    Soldier* sol = new Soldier("John", "Soldier", 100, 10);
    Soldier* sol2 = new Soldier("Smith", "Soldier", 100, 10);
    
    REQUIRE( sol->getName() == "John" );
    REQUIRE( sol2->getUnitClass() == "Soldier" );
    
    SECTION("Unit: soldier attack/counterattack") {
        REQUIRE( sol->getHp() == 100 );
        REQUIRE( sol2->getHp() == 100 );
        
        sol->attack(*sol2);
        
        REQUIRE( sol->getHp() == 95 );
        REQUIRE( sol2->getHp() == 90 );
    }
    
    delete sol;
    delete sol2;
}
