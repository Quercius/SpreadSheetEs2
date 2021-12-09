//
// Created by tommi on 08/12/2021.
//

#include "Values.h"

void Values::notify() {
    observer->update();
}

void Values::subscribe(Observer *o) {
    this->observer = o;
}

void Values::unsubscribe(Observer *o) {
    this->observer = nullptr;
}

const std::list<double> Values::getValues() const {
    return values;
}

void Values::addValue(double value) {
    values.push_back(value);
    notify();
}

void Values::removeValue(double value) {
    values.remove(value);
    notify();
}
