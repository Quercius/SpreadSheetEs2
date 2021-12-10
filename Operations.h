//
// Created by tommi on 08/12/2021.
//

#ifndef SPREADSHEETES2_OPERATIONS_H
#define SPREADSHEETES2_OPERATIONS_H


#include "Observer.h"
#include "Values.h"
#include <list>

class Operations : public Observer {
public:
    Operations(Values *subj) : subject(subj) {
        update();
        subject->subscribe(this);
    };

    virtual ~Operations() {
        subject->unsubscribe(this);
    };

    void update() override;

    double getMean() const;

    void setMean(double mean);

    int getMax() const;

    void setMax(double max);

    int getMin() const;

    void setMin(double min);

    int getSum() const;

    void setSum(double sum);

    void printValues();

private:
    Values *subject;
    std::list<int> values;
    double mean;
    int max;
    int min;
    int sum;
};


#endif //SPREADSHEETES2_OPERATIONS_H
