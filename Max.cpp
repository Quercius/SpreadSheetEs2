//
// Created by tommi on 01/01/2022.
//

#include "Max.h"

void Max::compute() {
    max = std::begin(opValues)->getValue();
    for (auto itr = std::begin(opValues); itr != std::end(opValues); itr++) {
        if (itr->getValue() > max)
            max = itr->getValue();
    }

}

int Max::getMax() const {
    return max;
}
