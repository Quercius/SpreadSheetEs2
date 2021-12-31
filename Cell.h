//
// Created by tommi on 29/12/2021.
//

#ifndef SPREADSHEETES2_CELL_H
#define SPREADSHEETES2_CELL_H


#include <string>

class Cell {
public:
    Cell(std::string x, int y, int value) : column(x), row(y), value(value) {}

    std::string getColumn();

    void setColumn(std::string x);

    int getRow() const;

    void setRow(int y);

    int getValue() const;

    void setValue(int value);

private:
    std::string column;
    int row;
    int value;
};


#endif //SPREADSHEETES2_CELL_H
