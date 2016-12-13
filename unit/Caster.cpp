#include "Caster.h"

Caster::Caster(unitClass title, int maxHp, int damage, int maxMana) : Soldier(title, maxHp, damage) {
    this->state = new CasterState(title, maxHp, damage, maxMana);
    this->spellbook = new std::map<SpellTitle, Spell*>();
    
    this->spellbook->insert(std::pair<SpellTitle, Spell*>(SpellTitle::FLAME_STRIKE, new FlameStrike()));
    this->spellbook->insert(std::pair<SpellTitle, Spell*>(SpellTitle::HEAL, new Heal()));
}

Caster::~Caster() {
    delete state;
    delete spellbook;
}

const int Caster::getMana() const {
    return state->getMana();
}
const int Caster::getMaxMana() const {
    return state->getMaxMana();
}
const std::map<SpellTitle, Spell*>& Caster::openSpellbook() const {
    return *spellbook;
}

void Caster::reduceMana(int cost) {
    this->ensureIsAlive();
    this->state->reduceMana(cost);
}

void Caster::restoreMana(int points) {
    this->ensureIsAlive();
    this->state->restoreMana(points);
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
    this->ensureIsAlive();
    
    this->reduceMana(spell.getCost());
    spell.action(target, 1);
    
    if ( target.getHp() != 0 ) {
        target.counterAttack(*this, target);
    }
}

void Caster::cast(Restore& spell, Unit& target) {
    this->ensureIsAlive();
    
    this->reduceMana(spell.getCost());
    spell.action(target, 2);
}
