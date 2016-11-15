#include "Soldier.h"

Soldier::Soldier(const std::string& name, const std::string& unitClass, int maxHp, int physDmg) : Unit(name, unitClass, maxHp, physDmg) {
    std::cout << "***" << this->name << " the " << this->unitClass << "___" << std::endl;
}

Soldier::~Soldier() {
    std::cout << "~~~" << this->name << " the " << this->unitClass << "___" << std::endl;
}

void Soldier::attack(Unit& enemy) {
    if ( this->dead() ) {
        // throw DeadAttackException("ERROR: zombie attack");
    }
    
    enemy.takeDamage(this->getPhysDmg(), 0);
    
    if ( !enemy.dead() ) {
        enemy.counterAttack(*this);
    }
}

void Soldier::counterAttack(Unit& enemy) {
    enemy.takeDamage(this->getPhysDmg()/2, 0);
}

void Soldier::takeDamage(int physDmg, int magDmg) {
    if ( this->dead() ) {
        // throw DeadUnderAttackException("ERROR: target is dead");
    }
    
    setHp(-physDmg, -magDmg);
}

void Soldier::restoreHp(int physPts, int magPts) {
    setHp(physPts, magPts);
}
