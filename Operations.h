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

    long double getMean() const;

    void setMean(long double mean);

    int getMax() const;

    void setMax(int max);

    int getMin() const;

    void setMin(int min);

    long int getSum() const;

    void setSum(long int sum);

    void printOperations();

    Values *getSubject() const;

    const std::vector<Cell> &getOpValues() const;

private:
    Values *subject;
    std::vector<Cell> values;
    long double mean;
    int max;
    int min;
    long int sum;
};


#endif //SPREADSHEETES2_OPERATIONS_H
