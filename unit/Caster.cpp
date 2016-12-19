#include "Caster.h"
#include "../modifier/Damage.h"

Caster::Caster(UnitClass title, int maxHp, int damage, int maxMana) : Soldier(title, maxHp, damage) {
    this->state = new CasterState(title, new Health(maxHp), damage, new Energy(maxMana));
    this->spellbook = new std::map<SpellTitle, Spell*>();
    
    this->spellbook->insert(std::pair<SpellTitle, Spell*>(SpellTitle::FLAME_STRIKE, new FlameStrike()));
    this->spellbook->insert(std::pair<SpellTitle, Spell*>(SpellTitle::HEAL, new Heal()));
}

Caster::~Caster() {
    delete state;
    delete spellbook;
}

const Energy& Caster::getEnergy() const {
    return state->getEnergy();
}
const std::map<SpellTitle, Spell*>& Caster::openSpellbook() const {
    return *spellbook;
}

void Caster::takeEnergyImpact(Modifier& mod) {
    this->ensureIsAlive();
    this->state->takeEnergyImpact(mod);
}

Spell& Caster::findSpell(SpellTitle title) const {
    Spell* spell;
    
    if ( this->openSpellbook().find(title) == this->openSpellbook().end() ) {
        throw SpellUnavailableException();
    }
    spell = openSpellbook().at(title);
    
    return *spell;
}

void Caster::cast(Harm& spell, Unit& target) {
    Damage dmg;
    
    this->ensureIsAlive();
    
    dmg = spell.getCost();
    
    this->takeEnergyImpact(dmg);
    spell.action(target, 1);
    
    if ( target.getHealth() != 0 ) {
        target.counterAttack(*this, target);
    }
}

void Caster::cast(Restore& spell, Unit& target) {
    Damage dmg;
    
    this->ensureIsAlive();
    
    dmg = spell.getCost();
    
    this->takeEnergyImpact(dmg);
    spell.action(target, 2);
}
