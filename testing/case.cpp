#include "../state/State.h"
#include "../unit/Unit.h"
#include "../unit/Soldier.h"
#include "../unit/Rogue.h"
#include "catch.hpp"

TEST_CASE("test Unit", "[Unit]") {
    Soldier* sol = new Soldier("John");
    Soldier* sol2 = new Soldier("Smith");
    Rogue* rog = new Rogue("Black");
    
    REQUIRE( sol->getName() == "John" );
    REQUIRE( sol2->getUnitClass() == "Soldier" );
    
    SECTION("Unit: soldier attack/counterattack") {
        REQUIRE( sol->getHp() == 100 );
        REQUIRE( sol2->getHp() == 100 );
        
        sol->attack(*sol2);
        
        REQUIRE( sol->getHp() == 95 );
        REQUIRE( sol2->getHp() == 90 );
    }
    
    SECTION("Unit: rogue attack") {
        rog->attack(*sol);
        
        REQUIRE (sol->getHp() == 92);
        REQUIRE (rog->getHp() == 60);
    }
    
    delete sol;
    delete sol2;
    delete rog;
}
