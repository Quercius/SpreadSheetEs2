//
// Created by tommi on 08/12/2021.
//

#include "Values.h"

void Values::notify() {
    for (auto itr = std::begin(observers); itr != std::end(observers); itr++) {
        (*itr)->update();
    }
}

void Values::subscribe(Observer *o) {
    observers.push_back(o);
}

void Values::unsubscribe(Observer *o) {
    observers.remove(o);
}

const std::list<double> Values::getValues() const {
    return values;
}


void Values::addValue(double value) {
    values.push_back(value);
}

void Values::removeValue(double value) {
    values.remove(value);
}
