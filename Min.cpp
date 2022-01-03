//
// Created by tommi on 01/01/2022.
//

#include "Min.h"

void Min::compute() {
    min = std::begin(opValues)->getValue();
    for (auto itr = std::begin(opValues); itr != std::end(opValues); itr++) {
        if (itr->getValue() < min)
            min = itr->getValue();
    }
}

int Min::getMin() {
    compute();
    return min;
}
