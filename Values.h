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

    Values(std::list<double> values) : values(values) {};

    virtual ~Values();

    void subscribe(Observer *o) override;

    void unsubscribe(Observer *o) override;

    void notify() override;

    const std::list<double> getValues() const;

    void addValue(double value);

    void removeValue(double value);


private:
    std::list<double> values;
    Observer *observer;
};


#endif //SPREADSHEETES2_VALUES_H
