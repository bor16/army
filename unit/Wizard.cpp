#include "Wizard.h"

Wizard::Wizard(const std::string& name, UnitClass title, int maxHp, int damage, int maxMana) : Soldier(name, title, maxHp, damage) {
    this->state = new CasterState(name, title, maxHp, damage, maxMana);
    this->spellbook = new std::map<SpellTitle, Spell*>();
    
    this->spellbook->insert(std::pair<SpellTitle, Spell*>(FLAME_STRIKE, new FlameStrike()));
    this->spellbook->insert(std::pair<SpellTitle, Spell*>(HEAL, new Heal()));
}

Wizard::~Wizard() {
    delete state;
}

const int Wizard::getMana() const {
    return state->getMana();
}
const int Wizard::getMaxMana() const {
    return state->getMaxMana();
}
const std::map<SpellTitle, Spell*>& Wizard::openSpellbook() const {
    return *spellbook;
}

void Wizard::reduceMana(int cost) {
    this->state->reduceMana(cost);
}

void Wizard::restoreMana(int points) {
    this->state->restoreMana(points);
}

Spell& Wizard::findSpell(SpellTitle title) const {
    Spell* spell;
    
    if ( this->openSpellbook().find(title) == this->openSpellbook().end() ) {
        // throw SpellUnavailableException();
    }
    spell = openSpellbook().at(FLAME_STRIKE);
    
    return *spell;
}

void Wizard::cast(SpellTitle title, Unit& target) {
    Spell& spell = findSpell(title);
    
    this->state->ensureIsAlive();
    
    this->reduceMana(spell.getCost());
    spell.action(target);
    
    if ( target.getHp() != 0 ) {
        target.counterAttack(*this);
    }
}
