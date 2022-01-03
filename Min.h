//
// Created by tommi on 01/01/2022.
//

#ifndef SPREADSHEETES2_MIN_H
#define SPREADSHEETES2_MIN_H

#include "Operation.h"

class Min : public Operation {
public:
    Min(Values *subj) : Operation(subj) {
        compute();
    }

    void compute() override;

    int getMin();

private:
    int min;
};


#endif //SPREADSHEETES2_MIN_H
