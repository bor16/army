#ifndef IOBSERVER_H
#define IOBSERVER_H

#include <iostream>

class IObserver {
    public:
        virtual ~IObserver() {}
        
        virtual void update() = 0;
        virtual void attachSubject(Unit* subject) = 0;
        virtual void detachSubject(Unit* subject) = 0;
        virtual void notifySubject() = 0;
};

#endif //IOBSERVER_H
