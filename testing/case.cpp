#include "../unit/Soldier.h"
#include "../unit/Rogue.h"
#include "catch.hpp"

TEST_CASE("test Soldier", "[Soldier]") {
    Soldier* sol = new Soldier();
    Soldier* sol2 = new Soldier();
    
    SECTION("Defaults") {
        REQUIRE( sol->getHp() == 100 );
        REQUIRE( sol->getMaxHp() == 100 );
        REQUIRE( sol->getDamage() == 10 );
        REQUIRE( sol->getTitle() == Class::SOLDIER );
    }
    
    SECTION("Attack") {
        sol->attack(*sol2);
        REQUIRE( sol2->getHp() == (static_cast<int>(Hp::SOLDIER) - static_cast<int>(Dmg::SOLDIER)) );
        REQUIRE( sol->getHp() == (static_cast<int>(Hp::SOLDIER) - static_cast<int>(Dmg::SOLDIER)/2) );
    }
    
    SECTION("Limit") {
        for ( int i = 0; i < 16; i++ ) {
            sol->attack(*sol2);
        }
        REQUIRE( sol2->getHp() >= 0 );
        REQUIRE( sol->getHp() == 55 );
        
        REQUIRE_THROWS_AS( sol2->attack(*sol), DeadActionException );
    }
    
    delete sol;
    delete sol2;
}

TEST_CASE("test Rogue", "[Rogue]") {
    Soldier* sol = new Soldier();
    Rogue* rog = new Rogue();
    Rogue* rog2 = new Rogue();
    
    SECTION("Defaults") {
        REQUIRE( rog->getHp() == 60 );
        REQUIRE( rog->getMaxHp() == 60 );
        REQUIRE( rog->getDamage() == 8 );
        REQUIRE( rog->getTitle() == Class::ROGUE );
    }
    
    SECTION("Attack") {
        sol->attack(*rog);
        REQUIRE( rog->getHp() == (static_cast<int>(Hp::ROGUE) - static_cast<int>(Dmg::SOLDIER)) );
        REQUIRE( sol->getHp() == (static_cast<int>(Hp::SOLDIER) - static_cast<int>(Dmg::ROGUE)/2) );
        
        rog->restoreHp(1000);
        sol->restoreHp(1000);
        REQUIRE( rog->getHp() == static_cast<int>(Hp::ROGUE) );
        REQUIRE( sol->getHp() == static_cast<int>(Hp::SOLDIER) );
        
        rog->attack(*sol);
        REQUIRE( sol->getHp() == (static_cast<int>(Hp::SOLDIER) - static_cast<int>(Dmg::ROGUE)) );
        REQUIRE( rog->getHp() == static_cast<int>(Hp::ROGUE) );
    }
    
    SECTION("Limit") {
        for ( int i = 0; i < 16; i++ ) {
            rog->attack(*rog2);
        }
        REQUIRE( rog2->getHp() >= 0 );
        REQUIRE( rog->getHp() == static_cast<int>(Hp::ROGUE) );
        
        REQUIRE_THROWS_AS( rog2->attack(*rog), DeadActionException );
    }
    
    delete sol;
    delete rog;
    delete rog2;
}
