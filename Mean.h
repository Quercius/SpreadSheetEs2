//
// Created by tommi on 01/01/2022.
//

#ifndef SPREADSHEETES2_MEAN_H
#define SPREADSHEETES2_MEAN_H

#include "Operation.h"

class Mean : public Operation {
public:
    Mean(Values *subj) : Operation(subj) {
        compute();
    }

    void compute() override;

    long double getMean() const;

private:
    long double mean;
};


#endif //SPREADSHEETES2_MEAN_H
