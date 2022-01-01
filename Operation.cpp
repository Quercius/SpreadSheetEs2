//
// Created by tommi on 01/01/2022.
//

#include "Operation.h"

void Operation::update() {
    opValues = subject->getValues();
    compute();
}

const std::vector<Cell> &Operation::getOpValues() const {
    return opValues;
}

Values *Operation::getSubject() const {
    return subject;
}
