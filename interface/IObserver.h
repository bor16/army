#ifndef IOBSERVER_H
#define IOBSERVER_H

#include <iostream>

class ISubject;
class IObserver {
    public:
        virtual ~IObserver() {}
        
        virtual void update() = 0;
        virtual void attachSubject(ISubject* subject) = 0;
        virtual void detachSubject(ISubject* subject) = 0;
        virtual void notifySubject() = 0;
};

#endif //IOBSERVER_H
