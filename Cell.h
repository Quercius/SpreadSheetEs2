//
// Created by tommi on 29/12/2021.
//

#ifndef SPREADSHEETES2_CELL_H
#define SPREADSHEETES2_CELL_H


#include <string>

class Cell {
public:
    Cell(char x, int y, int value) : x(x), y(y), value(value) {}

    const char getX() const;

    void setX(const char *x);

    int getY() const;

    void setY(int y);

    int getValue() const;

    void setValue(int value);

private:
    const char *x;
    int y;
    int value;
};


#endif //SPREADSHEETES2_CELL_H
