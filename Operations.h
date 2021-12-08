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
    Operations();

    virtual ~Operations();

    void update() override;

    double getMean() const;

    void setMean(double mean);

    double getMax() const;

    void setMax(double max);

    double getMin() const;

    void setMin(double min);

    double getSum() const;

    void setSum(double sum);

private:
    Values *subject;
    std::list<double> values;
    double mean;
    double max;
    double min;
    double sum;
};


#endif //SPREADSHEETES2_OPERATIONS_H
