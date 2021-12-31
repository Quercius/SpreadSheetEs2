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

void Values::addValue(std::string x, int y, int val) {
    int column;
    if (x == "a") column = 0;
    if (x == "b") column = 1;
    if (x == "c") column = 2;
    if (x == "d") column = 3;
    if (values[column * 11 + y].getValue() != 0)
        return;
    else {
        values[column * 11 + y].setValue(val);
        notify();
    }

}

void Values::removeValue(std::string x, int y) {
    int column;
    if (x == "a") column = 0;
    if (x == "b") column = 1;
    if (x == "c") column = 2;
    if (x == "d") column = 3;
    if (values[column * 11 + y].getValue() != 0)
        return;
    else {
        values[column * 11 + y].setValue(0);
        notify();
    }
}


void Values::printValues() {
    std::cout << "List:" << std::endl;
    for (auto itr = std::begin(this->values); itr != std::end(this->values); itr++) {
        std::cout << itr->getColumn() << itr->getRow() << ": " << itr->getValue() << " " << std::endl;
    }
}

Observer *Values::getObserver() const {
    return observer;
}

