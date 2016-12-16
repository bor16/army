#ifndef HEALTH_H
#define HEALTH_H

#include <iostream>

class Modifier;
class Health {
    protected:
        int points;
        int limit;
        
        int validatePoints(int points);
        int validateLimit(int limit);
        
    public:
        Health(int limit);
        Health(int points, int limit);
        virtual ~Health();
        
        const int getPoints() const;
        const int getLimit() const;
        
        void setLimit(int limit);
        void setPoints(int points);
        void operator=(int points);
        
        void operator+=(const Modifier& modifier);
        
        const bool operator==(int value) const;
        const bool operator!=(int value) const;
};

std::ostream& operator<<(std::ostream& out, const Health& health);

#endif //HEALTH_H
