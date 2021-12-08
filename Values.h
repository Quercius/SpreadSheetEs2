//
// Created by tommi on 08/12/2021.
//

#ifndef SPREADSHEETES2_VALUES_H
#define SPREADSHEETES2_VALUES_H


#include "Subject.h"
#include <vector>
#include <list>

class Values : public Subject {
public:
    Values();

    virtual ~Values();

    void subscribe(Observer *o) override;

    void unsubscribe(Observer *o) override;

    void notify() override;

    const std::list<double> getValues() const;

private:
    std::list<double> values;
    std::list<Observer *> observers;
};


#endif //SPREADSHEETES2_VALUES_H
