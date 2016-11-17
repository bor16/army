#include "Rogue.h"

Rogue::Rogue(const std::string& name, const std::string& unitClass, int maxHp, int physDmg) : Soldier(name, unitClass, maxHp, physDmg) {
    std::cout << "***" << this->name << " the " << this->unitClass << "___" << std::endl;
}

Rogue::~Rogue() {
    std::cout << "~~~" << this->name << " the " << this->unitClass << "___" << std::endl;
}

void Rogue::attack(Unit& enemy) {
    if ( this->dead() ) {
        // throw DeadAttackException("ERROR: zombie attack");
    }
    
    enemy.takeDamage(this->getPhysDmg(), 0);
}
