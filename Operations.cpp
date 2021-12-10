//
// Created by tommi on 08/12/2021.
//

#include "Operations.h"

void Operations::update() {
    this->values = subject->getValues();

    //update sum
    int actualSum = 0.0;
    for (auto itr = std::begin(this->values); itr != std::end(this->values); itr++) {
        actualSum += *(itr);
    }
    setSum(actualSum);

    //update mean
    int sumToMean = 0.0;
    for (auto itr = std::begin(this->values); itr != std::end(this->values); itr++) {
        sumToMean += *(itr);
    }
    setMean(sumToMean / this->values.size());

    //update min
    int actualMin = *(std::begin(this->values));
    for (auto itr = std::begin(this->values); itr != std::end(this->values); itr++) {
        if (*itr <= actualMin) {
            actualMin = *itr;
        }
    }
    setMin(actualMin);

    //update max
    int actualMax = *(std::begin(this->values));
    for (auto itr = std::begin(this->values); itr != std::end(this->values); itr++) {
        if (*itr >= actualMax) {
            actualMax = *itr;
        }
    }
    setMax(actualMax);
}

double Operations::getMean() const {
    return mean;
}

void Operations::setMean(double mean) {
    Operations::mean = mean;
}

int Operations::getMax() const {
    return max;
}

void Operations::setMax(double max) {
    Operations::max = max;
}

int Operations::getMin() const {
    return min;
}

void Operations::setMin(double min) {
    Operations::min = min;
}

int Operations::getSum() const {
    return sum;
}

void Operations::setSum(double sum) {
    Operations::sum = sum;
}
