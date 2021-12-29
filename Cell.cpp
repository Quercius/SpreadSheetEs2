//
// Created by tommi on 29/12/2021.
//

#include "Cell.h"

const char Cell::getX() const {
    return *x;
}

void Cell::setX(const char *x) {
    if (x == "a" || x == "b" || x == "c" || x == "d") {
        Cell::x = x;
    }
}

int Cell::getY() const {
    return y;
}

void Cell::setY(int y) {
    if (y < 12)
        Cell::y = y;
}

int Cell::getValue() const {
    return value;
}

void Cell::setValue(int value) {
    Cell::value = value;
}
