#include "Damage.h"

Damage::Damage(int points) {
    setPoints(points);
}

Damage::~Damage() {}

int Damage::validatePoints(int value) {
    if ( value > 0 ) {
        value = 0;
    }
    return value;
}

const int Damage::getPoints() const {
    return this->points;
}

void Damage::setPoints(int value) {
    value *= -1;
    this->points = validatePoints(value);
}

void Damage::operator=(int value) {
    setPoints(value);
}
void Damage::operator+=(int value) {
    int result = this->points - value;
    
    this->points = validatePoints(result);
}
void Damage::operator-=(int value) {
    int result = this->points + value;
    
    this->points = validatePoints(result);
}
void Damage::operator*=(int value) {
    int result = this->points * value;
    
    this->points = validatePoints(result);
}
void Damage::operator/=(int value) {
    int result = this->points / value;
    
    this->points = validatePoints(result);
}
