//
// Created by tommi on 08/12/2021.
//

#include <iostream>
#include <list>
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

const std::vector<Cell> Values::getValues() const {
    return values;
}

/*void Values::addValue(std::char) {
    values.push_back(value);
    notify();
}

void Values::removeValue(int value) {
    values.remove(value);
    notify();
}

void Values::printValues() {
    std::cout << "List:" << std::endl;
    for (auto itr = std::begin(this->values); itr != std::end(this->values); itr++) {
        std::cout << *itr << " " << std::endl;
    }
}*/

Observer *Values::getObserver() const {
    return observer;
}
