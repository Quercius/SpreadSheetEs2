//
// Created by tommi on 08/12/2021.
//

#include <iostream>
#include "Operations.h"

void Operations::update() {
    this->values = subject->getValues();

    //update sum
    long int actualSum = 0;
    for (auto itr = std::begin(this->values); itr != std::end(this->values); itr++) {
        actualSum += *(itr);
    }
    setSum(actualSum);

    //update mean
    double sumToMean = 0.0;
    for (auto itr = std::begin(this->values); itr != std::end(this->values); itr++) {
        sumToMean += *(itr);
    }
    if (this->values.size() != 0) {
        setMean(sumToMean / this->values.size());
    } else {
        setMean(0.0);
    }

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

long double Operations::getMean() const {
    return mean;
}

void Operations::setMean(long double mean) {
    Operations::mean = mean;
}

int Operations::getMax() const {
    return max;
}

void Operations::setMax(int max) {
    Operations::max = max;
}

int Operations::getMin() const {
    return min;
}

void Operations::setMin(int min) {
    Operations::min = min;
}

long int Operations::getSum() const {
    return sum;
}

void Operations::setSum(long int sum) {
    Operations::sum = sum;
}

void Operations::printOperations() {
    std::cout << "\nMax:" << this->getMax() << "\nMin: " << this->getMin()
              << "\nSum: " << this->getSum() << "\nMean: " << this->getMean() << std::endl;

}
