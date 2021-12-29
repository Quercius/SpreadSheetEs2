//
// Created by tommi on 08/12/2021.
//

#ifndef SPREADSHEETES2_SUBJECT_H
#define SPREADSHEETES2_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual ~Subject() = default;

    virtual void subscribe(Observer *o) = 0;

    virtual void unsubscribe(Observer *o) = 0;

    virtual void notify() = 0;
};

#endif //SPREADSHEETES2_SUBJECT_H

