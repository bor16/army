#include "MagDamage.h"

MagDamage::MagDamage(int points) {
    setPoints(points);
    this->type = 2;
}

MagDamage::~MagDamage() {}

int MagDamage::validatePoints(int value) {
    if ( value > 0 ) {
        value = 0;
    }
    return value;
}

const int MagDamage::getPoints() const {
    return this->points;
}

const int MagDamage::getType() const {
    return this->type;
}

void MagDamage::setPoints(int value) {
    value *= -1;
    this->points = validatePoints(value);
}

void MagDamage::operator=(int value) {
    setPoints(value);
}
void MagDamage::operator+=(int value) {
    int result = this->points - value;
    
    this->points = validatePoints(result);
}
void MagDamage::operator-=(int value) {
    int result = this->points + value;
    
    this->points = validatePoints(result);
}
void MagDamage::operator*=(int value) {
    int result = this->points * value;
    
    this->points = validatePoints(result);
}
void MagDamage::operator/=(int value) {
    int result = this->points / value;
    
    this->points = validatePoints(result);
}

std::ostream& operator<<(std::ostream& out, const MagDamage& mdmg) {
    out << mdmg.getType();
    
    return out;
}
