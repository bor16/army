#include "WolfHealth.h"
#include "../modifier/MagDamage.h"

WolfHealth::WolfHealth(int limit) : Health(limit) {}

WolfHealth::WolfHealth(int points, int limit) : Health(points, limit) {}

WolfHealth::~WolfHealth() {}

void WolfHealth::operator+=(Modifier& mod) {
    Health::operator+=(mod);
}

void WolfHealth::operator+=(MagDamage& mod) {
    int result;
    
    mod *= 2;
    
    result = this->points + mod.getPoints();
    this->points = validatePoints(result);
}
