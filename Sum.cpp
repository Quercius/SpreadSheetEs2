//
// Created by tommi on 01/01/2022.
//

#include "Sum.h"

void Sum::compute() {
    sum = 0;
    for (auto itr = std::begin(opValues); itr != std::end(opValues); itr++) {
        sum += itr->getValue();
    }
}

int Sum::getSum() const {
    return sum;
}
