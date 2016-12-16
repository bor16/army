#include "Aid.h"

Aid::Aid(int points) {
    setPoints(points);
}

Aid::~Aid() {}

int Aid::validatePoints(int value) {
    if ( value < 0 ) {
        value = 0;
    }
    return value;
}

const int Aid::getPoints() const {
    return this->points;
}

void Aid::setPoints(int value) {
    this->points = validatePoints(value);
}

void Aid::operator=(int value) {
    setPoints(value);
}
void Aid::operator+=(int value) {
    int result = this->points + value;
    
    this->points = validatePoints(result);
}
void Aid::operator-=(int value) {
    int result = this->points - value;
    
    this->points = validatePoints(result);
}
void Aid::operator*=(int value) {
    int result = this->points * value;
    
    this->points = validatePoints(result);
}
void Aid::operator/=(int value) {
    int result = this->points / value;
    
    this->points = validatePoints(result);
}
