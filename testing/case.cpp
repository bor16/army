#include "../state/State.h"
#include "../state/BerserkerState.h"
#include "../state/CasterState.h"
#include "../state/WolfState.h"
#include "../unit/Unit.h"
#include "../unit/Berserker.h"
#include "../unit/Rogue.h"
#include "../unit/Soldier.h"
#include "../unit/Vampire.h"
#include "../unit/Werewolf.h"
#include "../unit/Wizard.h"
#include "catch.hpp"

TEST_CASE("test Unit", "[Unit]") {
    Berserker* ber = new Berserker("Ber");
    Rogue* rog = new Rogue("Rog");
    Soldier* sol = new Soldier("Sol");
    Vampire* vam = new Vampire("Vam");
    Werewolf* wer = new Werewolf("Wer");
    Wizard* wiz = new Wizard("Wiz");
    
    SECTION("Unit: defaults") {
        REQUIRE( ber->getHp() == 70 );
        REQUIRE( rog->getHp() == 60 );
        REQUIRE( sol->getHp() == 100 );
        REQUIRE( vam->getHp() == 40 );
        REQUIRE( wer->getHp() == 80 );
        REQUIRE( wiz->getHp() == 50 );
    }
    
    SECTION("Unit: attack/counterAttack") {
        sol->attack(*rog);
        REQUIRE( rog->getHp() == 50 );
        REQUIRE( sol->getHp() == 96 );
        rog->attack(*sol);
        REQUIRE( sol->getHp() == 88 );
        REQUIRE( rog->getHp() == 50 );
    }
    
    SECTION("Unit: Werewolf/Vampire") {
        SECTION("Werewolf/Vampire attack/counterAttack") {
            wer->attack(*vam);
            REQUIRE( vam->getHp() == 33 );
            REQUIRE( wer->getHp() == 77 );
            
            vam->attack(*wer);
            REQUIRE( wer->getHp() == 71 );
            REQUIRE( vam->getHp() == 32 );
        }
        SECTION("Vampire/Werewolf attack/counterAttack") {
            vam->attack(*wer);
            REQUIRE( wer->getHp() == 74 );
            REQUIRE( vam->getHp() == 36 );
            
            wer->attack(*vam);
            REQUIRE( vam->getHp() == 29 );
            REQUIRE( wer->getHp() == 71 );
        }
    }
    
    delete ber;
    delete rog;
    delete sol;
    delete vam;
    delete wer;
    delete wiz;
}

TEST_CASE("test SpellCaster", "[SpellCaster]") {
    Wizard* wiz = new Wizard("Wiz");
    Soldier* sol = new Soldier("Sol");
    
    SECTION("Wizard") {
        wiz->cast(SpellTitle::FLAME_STRIKE, *sol);
        REQUIRE(sol->getHp() == 80);
        REQUIRE(wiz->getHp() == 45);
        REQUIRE(wiz->getMana() == 60);
    }
    
    delete wiz;
    delete sol;
}
