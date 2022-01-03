//
// Created by tommi on 01/01/2022.
//

#ifndef SPREADSHEETES2_SUM_H
#define SPREADSHEETES2_SUM_H

#include "Operation.h"


class Sum : public Operation {
public:
    Sum(Values *subj) : Operation(subj) {
        compute();
    }

    void compute() override;

    int getSum();

private:
    int sum;
};


#endif //SPREADSHEETES2_SUM_H
