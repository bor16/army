#ifndef ISUBJECT_H
#define ISUBJECT_H

#include <iostream>

class Necromancer;
class ISubject {
    public:
        virtual ~ISubject() {}
        
        virtual void attach(Necromancer* observer) = 0;
        virtual void detach(Necromancer* observer) = 0;
        virtual void notify() = 0;
};

#endif //ISUBJECT_H
