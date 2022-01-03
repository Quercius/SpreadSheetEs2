//
// Created by tommi on 01/01/2022.
//

#ifndef SPREADSHEETES2_MAX_H
#define SPREADSHEETES2_MAX_H

#include "Operation.h"

class Max : public Operation {
public:
    Max(Values *subj) : Operation(subj) {
        compute();
    }

    void compute() override;

    int getMax();

private:
    int max;
};


#endif //SPREADSHEETES2_MAX_H
