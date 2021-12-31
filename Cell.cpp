//
// Created by tommi on 29/12/2021.
//

#include "Cell.h"

char Cell::getColumn() {
    return column;
}

void Cell::setColumn(const char *x) {
    if (x == "a" || x == "b" || x == "c" || x == "d") {
        Cell::column = *x;
    }
}

int Cell::getRow() const {
    return row;
}

void Cell::setRow(int y) {
    if (y < 12)
        Cell::row = y;
}

int Cell::getValue() const {
    return value;
}

void Cell::setValue(int value) {
    Cell::value = value;
}
