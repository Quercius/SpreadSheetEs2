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

const std::list<int> Values::getValues() const {
    return values;
}

void Values::addValue(int value) {
    values.push_back(value);
    notify();
}

void Values::removeValue(int value) {
    values.remove(value);
    notify();
}
