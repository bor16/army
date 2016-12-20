#include "Health.h"
#include "../modifier/Modifier.h"

Health::Health(int limit) {
    setLimit(limit);
    setPoints(limit);
}

Health::Health(int points, int limit) {
    setLimit(limit);
    setPoints(points);
}

Health::~Health() {}

int Health::validatePoints(int points) {
    if ( points > this->limit ) {
        points = this->limit;
    }
    if ( points < 0 ) {
        points = 0;
    }
    return points;
}

int Health::validateLimit(int limit) {
    if ( limit < 0 ) {
        limit = 0;
    }
    return limit;
}

const int Health::getPoints() const {
    return this->points;
}
const int Health::getLimit() const {
    return this->limit;
}

void Health::setLimit(int limit) {
    this->limit = validateLimit(limit);
}
void Health::setPoints(int points) {
    this->points = validatePoints(points);
}
void Health::operator=(int points) {
    setPoints(points);
}

void Health::operator+=(const Modifier& mod) {
    int result = this->points + mod.getPoints();
    
    this->points = validatePoints(result);
}

const bool Health::operator==(int value) const {
    return this->points == value;
}

const bool Health::operator!=(int value) const {
    return !(*this == value);
}

std::ostream& operator<<(std::ostream& out, const Health& health) {
    out << health.getPoints() << "/" << health.getLimit();
    
    return out;
}
