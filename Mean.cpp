//
// Created by tommi on 01/01/2022.
//

#include "Mean.h"

void Mean::compute() {
    int count = 0;
    mean = 0;
    for (auto itr = std::begin(opValues); itr != std::end(opValues); itr++) {
        if (itr->getValue() != 0) {
            count++;
            mean += itr->getValue();
        }
    }
    mean /= count;
}

long double Mean::getMean() const {
    return mean;
}
