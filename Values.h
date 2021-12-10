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

    Values(std::list<int> vls) : values(vls) {};

    virtual ~Values() {};

    void subscribe(Observer *o) override;

    void unsubscribe(Observer *o) override;

    void notify() override;

    const std::list<int> getValues() const;

    void addValue(int value);

    void removeValue(int value);


private:
    std::list<int> values;
    Observer *observer;
};


#endif //SPREADSHEETES2_VALUES_H
