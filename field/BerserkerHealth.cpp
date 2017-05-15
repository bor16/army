#include "BerserkerHealth.h"
#include "../modifier/MagDamage.h"

BerserkerHealth::BerserkerHealth(int limit) : Health(limit) {}

BerserkerHealth::BerserkerHealth(int points, int limit) : Health(points, limit) {}

BerserkerHealth::~BerserkerHealth() {}

void BerserkerHealth::operator+=(const Modifier& mod) {
    Health::operator+=(mod);
}

void BerserkerHealth::operator+=(const MagDamage& mod) {
    std::cout << "F#!K you wizard!" << std::endl;
}
