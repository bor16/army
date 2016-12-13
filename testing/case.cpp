#include "../unit/Soldier.h"
#include "../unit/Rogue.h"
#include "../unit/Berserker.h"
#include "../unit/Wizard.h"
#include "../unit/Healer.h"
#include "../unit/Priest.h"
#include "../unit/Werewolf.h"
// #include "../unit/Necromancer.h"
#include "../spell/Spell.h"
#include "catch.hpp"

TEST_CASE("test Soldier", "[Soldier]") {
    Soldier* sol = new Soldier();
    Soldier* sol2 = new Soldier();
    
    SECTION("Defaults") {
        REQUIRE( sol->getHp() == 100 );
        REQUIRE( sol->getMaxHp() == 100 );
        REQUIRE( sol->getDamage() == 10 );
        REQUIRE( sol->getTitle() == unitClass::SOLDIER );
    }
    
    SECTION("Attack") {
        sol->attack(*sol2, *sol);
        REQUIRE( sol2->getHp() == ((int)Hp::SOLDIER - (int)Dmg::SOLDIER) );
        REQUIRE( sol->getHp() == ((int)Hp::SOLDIER - (int)Dmg::SOLDIER/2) );
    }
    
    SECTION("Limit") {
        for ( int i = 0; i < 16; i++ ) {
            sol->attack(*sol2, *sol);
        }
        REQUIRE( sol2->getHp() >= 0 );
        REQUIRE( sol->getHp() == 55 );
        
        REQUIRE_THROWS_AS( sol2->attack(*sol, *sol2), DeadActionException );
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
        REQUIRE( rog->getTitle() == unitClass::ROGUE );
    }
    
    SECTION("Attack") {
        sol->attack(*rog, *sol);
        REQUIRE( rog->getHp() == ((int)Hp::ROGUE - (int)Dmg::SOLDIER) );
        REQUIRE( sol->getHp() == ((int)Hp::SOLDIER - (int)Dmg::ROGUE/2) );
        
        rog->restoreHp(1000);
        sol->restoreHp(1000);
        REQUIRE( rog->getHp() == (int)Hp::ROGUE );
        REQUIRE( sol->getHp() == (int)Hp::SOLDIER );
        
        rog->attack(*sol, *rog);
        REQUIRE( sol->getHp() == ((int)Hp::SOLDIER - (int)Dmg::ROGUE) );
        REQUIRE( rog->getHp() == (int)Hp::ROGUE );
    }
    
    SECTION("Limit") {
        for ( int i = 0; i < 16; i++ ) {
            rog->attack(*rog2, *rog);
        }
        REQUIRE( rog2->getHp() >= 0 );
        REQUIRE( rog->getHp() == (int)Hp::ROGUE );
        
        REQUIRE_THROWS_AS( rog2->attack(*rog, *rog2), DeadActionException );
    }
    
    delete sol;
    delete rog;
    delete rog2;
}

TEST_CASE("test Berserker", "[Berserker]") {
    Berserker* ber = new Berserker();
    
    SECTION("TakeMagDamage") {
        ber->takeMagDamage(16);
        REQUIRE( ber->getHp() == (int)Hp::BERSERKER );
    }
    
    delete ber;
}

TEST_CASE("test Wizard", "[Wizard]") {
    Wizard* wiz = new Wizard();
    Healer* hea = new Healer();
    Priest* pri = new Priest();
    Soldier* sol = new Soldier();
    
    SECTION("Defaults") {
        REQUIRE( wiz->getHp() == 60 );
        REQUIRE( wiz->getMaxHp() == 60 );
        REQUIRE( wiz->getDamage() == 4 );
        REQUIRE( wiz->getMana() == 200 );
        REQUIRE( wiz->getTitle() == unitClass::WIZARD );
    }
    
    SECTION("Cast") {
        CHECK( wiz->getHp() == 60 );
        wiz->cast(dynamic_cast<Harm&>(wiz->findSpell(SpellTitle::FLAME_STRIKE)), *sol);
        REQUIRE( sol->getHp() == ((int)Hp::SOLDIER - (int)Power::FLAME_STRIKE) );
        CHECK( wiz->getHp() == 55 );
        wiz->cast(dynamic_cast<Restore&>(wiz->findSpell(SpellTitle::HEAL)), *sol);
        REQUIRE( sol->getHp() == (int)Hp::SOLDIER - (int)Power::FLAME_STRIKE/2 );
        REQUIRE( wiz->getHp() == 55 );
        
        sol->restoreHp(1000);
        hea->cast(dynamic_cast<Harm&>(hea->findSpell(SpellTitle::FLAME_STRIKE)), *sol);
        REQUIRE( sol->getHp() == (int)Hp::SOLDIER - (int)Power::FLAME_STRIKE/2 );
        hea->cast(dynamic_cast<Restore&>(hea->findSpell(SpellTitle::HEAL)), *sol);
        REQUIRE( sol->getHp() == (int)Hp::SOLDIER );
        
        pri->cast(dynamic_cast<Harm&>(pri->findSpell(SpellTitle::FLAME_STRIKE)), *sol);
        REQUIRE( sol->getHp() == (int)Hp::SOLDIER - (int)Power::FLAME_STRIKE/2 );
        pri->cast(dynamic_cast<Restore&>(pri->findSpell(SpellTitle::HEAL)), *sol);
        REQUIRE( sol->getHp() == (int)Hp::SOLDIER );
    }
    
    delete wiz;
    delete hea;
    delete pri;
    delete sol;
}

TEST_CASE("test Werewolf", "[Werewolf]") {
    Werewolf* wer = new Werewolf();
    Soldier* sol = new Soldier();
    Wizard* wiz = new Wizard();
    
    SECTION("shapeShift") {
        CHECK( wer->getHp() == (int)Hp::WEREWOLF );
        
        wer->shapeShift();
        CHECK( wer->getHp() == (int)Hp::WEREWOLF*2 );
        
        wer->shapeShift();
        CHECK( wer->getHp() == (int)Hp::WEREWOLF );
    }
    
    SECTION("shapeShift + damage") {
        REQUIRE( wer->getHp() == (int)Hp::WEREWOLF );
        
        sol->attack(*wer, *sol);
        CHECK( wer->getHp() == ((int)Hp::WEREWOLF - (int)Dmg::SOLDIER) );
        wer->shapeShift();
        CHECK( wer->getHp() == ((int)Hp::WEREWOLF*2 - (int)Dmg::SOLDIER) );
        wer->shapeShift();
        CHECK( wer->getHp() == ((int)Hp::WEREWOLF - (int)Dmg::SOLDIER) );
        
        wer->restoreHp(1000);
        REQUIRE( wer->getHp() == (int)Hp::WEREWOLF );
        
        sol->attack(*wer, *sol);
        CHECK( wer->getHp() == ((int)Hp::WEREWOLF - (int)Dmg::SOLDIER) );
        wer->shapeShift();
        sol->attack(*wer, *sol);
        CHECK( wer->getHp() == ((int)Hp::WEREWOLF*2 - (int)Dmg::SOLDIER*2) );
        wer->shapeShift();
        CHECK( wer->getHp() == ((int)Hp::WEREWOLF - (int)Dmg::SOLDIER*2) );
    }
    
    delete wer;
    delete wiz;
    delete sol;
}
