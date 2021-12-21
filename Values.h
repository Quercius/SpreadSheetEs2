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

    Values() {};

    virtual ~Values() {};

    virtual void subscribe(Observer *o) override;

    virtual void unsubscribe(Observer *o) override;

    virtual void notify() override;

    const std::list<int> getValues() const;

    void addValue(int value);

    void removeValue(int value);

    void printValues();

    const std::list<Observer *> &getObservers() const;

private:
    std::list<int> values;
    std::list<Observer *> observers;


};


#endif //SPREADSHEETES2_VALUES_H
