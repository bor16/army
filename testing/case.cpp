#include "../unit/Soldier.h"
#include "../unit/Rogue.h"
#include "../unit/Berserker.h"
#include "../unit/Wizard.h"
#include "../unit/Healer.h"
#include "../unit/Priest.h"
#include "../unit/Werewolf.h"
#include "../unit/Warlock.h"
#include "../unit/Demon.h"
// #include "../unit/Necromancer.h"
#include "../spell/Spell.h"
#include "../modifier/Aid.h"
#include "../modifier/Damage.h"
#include "catch.hpp"

TEST_CASE("test Soldier", "[Soldier]") {
    Soldier* sol = new Soldier();
    Soldier* sol2 = new Soldier();
    
    SECTION("Defaults") {
        REQUIRE( sol->getHealth().getPoints() == 100 );
        REQUIRE( sol->getHealth().getLimit() == 100 );
        REQUIRE( sol->getDamage() == 10 );
        REQUIRE( sol->getTitle() == UnitClass::SOLDIER );
    }
    
    SECTION("Attack") {
        sol->attack(*sol2, *sol);
        REQUIRE( sol2->getHealth().getPoints() == ((int)Hp::SOLDIER - (int)Dmg::SOLDIER) );
        REQUIRE( sol->getHealth().getPoints() == ((int)Hp::SOLDIER - (int)Dmg::SOLDIER/2) );
    }
    
    SECTION("Limit") {
        for ( int i = 0; i < 16; i++ ) {
            sol->attack(*sol2, *sol);
        }
        REQUIRE( sol2->getHealth().getPoints() >= 0 );
        REQUIRE( sol->getHealth().getPoints() == 55 );
        
        REQUIRE_THROWS_AS( sol2->attack(*sol, *sol2), DeadActionException );
    }
    
    delete sol;
    delete sol2;
}

TEST_CASE("test Rogue", "[Rogue]") {
    Soldier* sol = new Soldier();
    Rogue* rog = new Rogue();
    Rogue* rog2 = new Rogue();
    Aid aid = Aid(1000);
    
    SECTION("Defaults") {
        REQUIRE( rog->getHealth().getPoints() == 60 );
        REQUIRE( rog->getHealth().getLimit() == 60 );
        REQUIRE( rog->getDamage() == 8 );
        REQUIRE( rog->getTitle() == UnitClass::ROGUE );
    }
    
    SECTION("Attack") {
        sol->attack(*rog, *sol);
        REQUIRE( rog->getHealth().getPoints() == ((int)Hp::ROGUE - (int)Dmg::SOLDIER) );
        REQUIRE( sol->getHealth().getPoints() == ((int)Hp::SOLDIER - (int)Dmg::ROGUE/2) );
        
        rog->takeImpact(aid);
        sol->takeImpact(aid);
        REQUIRE( rog->getHealth().getPoints() == (int)Hp::ROGUE );
        REQUIRE( sol->getHealth().getPoints() == (int)Hp::SOLDIER );
        
        rog->attack(*sol, *rog);
        REQUIRE( sol->getHealth().getPoints() == ((int)Hp::SOLDIER - (int)Dmg::ROGUE) );
        REQUIRE( rog->getHealth().getPoints() == (int)Hp::ROGUE );
    }
    
    SECTION("Limit") {
        for ( int i = 0; i < 16; i++ ) {
            rog->attack(*rog2, *rog);
        }
        REQUIRE( rog2->getHealth().getPoints() >= 0 );
        REQUIRE( rog->getHealth().getPoints() == (int)Hp::ROGUE );
        
        REQUIRE_THROWS_AS( rog2->attack(*rog, *rog2), DeadActionException );
    }
    
    delete sol;
    delete rog;
    delete rog2;
}

TEST_CASE("test Berserker", "[Berserker]") {
    Berserker* ber = new Berserker();
    Damage dmg = Damage(16);
    
    SECTION("TakeMagDamage") {
        ber->takeMagDamage(dmg);
        REQUIRE( ber->getHealth().getPoints() == (int)Hp::BERSERKER );
    }
    
    delete ber;
}

TEST_CASE("test Wizard", "[Wizard]") {
    Wizard* wiz = new Wizard();
    Healer* hea = new Healer();
    Priest* pri = new Priest();
    Soldier* sol = new Soldier();
    Aid aid = Aid(1000);
    
    SECTION("Defaults") {
        REQUIRE( wiz->getHealth().getPoints() == 60 );
        REQUIRE( wiz->getHealth().getLimit() == 60 );
        REQUIRE( wiz->getDamage() == 4 );
        REQUIRE( wiz->getEnergy().getPoints() == 200 );
        REQUIRE( wiz->getTitle() == UnitClass::WIZARD );
    }
    
    SECTION("Cast") {
        CHECK( wiz->getHealth().getPoints() == 60 );
        wiz->cast(dynamic_cast<Harm&>(wiz->findSpell(SpellTitle::FLAME_STRIKE)), *sol);
        REQUIRE( sol->getHealth().getPoints() == ((int)Hp::SOLDIER - (int)Power::FLAME_STRIKE) );
        CHECK( wiz->getHealth().getPoints() == 55 );
        wiz->cast(dynamic_cast<Restore&>(wiz->findSpell(SpellTitle::HEAL)), *sol);
        REQUIRE( sol->getHealth().getPoints() == (int)Hp::SOLDIER - (int)Power::FLAME_STRIKE/2 );
        REQUIRE( wiz->getHealth().getPoints() == 55 );
        
        sol->takeImpact(aid);
        hea->cast(dynamic_cast<Harm&>(hea->findSpell(SpellTitle::FLAME_STRIKE)), *sol);
        REQUIRE( sol->getHealth().getPoints() == (int)Hp::SOLDIER - (int)Power::FLAME_STRIKE/2 );
        hea->cast(dynamic_cast<Restore&>(hea->findSpell(SpellTitle::HEAL)), *sol);
        REQUIRE( sol->getHealth().getPoints() == (int)Hp::SOLDIER );
        
        pri->cast(dynamic_cast<Harm&>(pri->findSpell(SpellTitle::FLAME_STRIKE)), *sol);
        REQUIRE( sol->getHealth().getPoints() == (int)Hp::SOLDIER - (int)Power::FLAME_STRIKE/2 );
        pri->cast(dynamic_cast<Restore&>(pri->findSpell(SpellTitle::HEAL)), *sol);
        REQUIRE( sol->getHealth().getPoints() == (int)Hp::SOLDIER );
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
    Aid aid = Aid(1000);
    
    SECTION("shapeShift") {
        CHECK( wer->getHealth().getPoints() == (int)Hp::WEREWOLF );
        
        wer->shapeShift();
        CHECK( wer->getHealth().getPoints() == (int)Hp::WEREWOLF*2 );
        
        wer->shapeShift();
        CHECK( wer->getHealth().getPoints() == (int)Hp::WEREWOLF );
    }
    
    SECTION("shapeShift + damage") {
        REQUIRE( wer->getHealth().getPoints() == (int)Hp::WEREWOLF );
        
        sol->attack(*wer, *sol);
        CHECK( wer->getHealth().getPoints() == ((int)Hp::WEREWOLF - (int)Dmg::SOLDIER) );
        wer->shapeShift();
        CHECK( wer->getHealth().getPoints() == ((int)Hp::WEREWOLF*2 - (int)Dmg::SOLDIER) );
        wer->shapeShift();
        CHECK( wer->getHealth().getPoints() == ((int)Hp::WEREWOLF - (int)Dmg::SOLDIER) );
        
        wer->takeImpact(aid);
        REQUIRE( wer->getHealth().getPoints() == (int)Hp::WEREWOLF );
        
        sol->attack(*wer, *sol);
        CHECK( wer->getHealth().getPoints() == ((int)Hp::WEREWOLF - (int)Dmg::SOLDIER) );
        wer->shapeShift();
        sol->attack(*wer, *sol);
        CHECK( wer->getHealth().getPoints() == ((int)Hp::WEREWOLF*2 - (int)Dmg::SOLDIER*2) );
        wer->shapeShift();
        CHECK( wer->getHealth().getPoints() == ((int)Hp::WEREWOLF - (int)Dmg::SOLDIER*2) );
    }
    
    delete wer;
    delete wiz;
    delete sol;
}

TEST_CASE("test Warlock", "[Warlock]") {
    Warlock* war = new Warlock();
    
    SECTION("default") {
        war->summonFiend();
        
        war->getFiend().attack(*war, war->getFiend());
        CHECK( war->getHealth().getPoints() == (int)Hp::WARLOCK - (int)Dmg::DEMON );
        
        war->dismissFiend();
        REQUIRE_THROWS_AS( war->getFiend(), NoFiendException );
    }
    
    delete war;
}
