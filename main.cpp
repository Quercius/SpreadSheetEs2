
#include <iostream>
#include <ncurses/ncurses.h>
#include <list>
#include "Values.h"
#include "version.h"
#include "Max.h"
#include "Min.h"
#include "Mean.h"
#include "Sum.h"


int main() {
    Values values;
    Max max = Max(&values);
    Min min = Min(&values);
    Mean mean = Mean(&values);
    Sum sum = Sum(&values);

    int newValue = 0;

    initscr();

    noecho();

    int x, y, xVal, yVal, xOp, yOp, xLeg, yLeg;
    x = 18;
    y = 2;
    xVal = 3;
    yVal = 6;
    xOp = 80;
    yOp = 6;
    xLeg = 5;
    yLeg = 20;

    int nCifre = 0;


    std::vector<Cell> tmpValues = values.getValues();
    int nPrinted = 0;

    //print column values
    mvprintw(yVal - 2, xVal + 11, "a");
    mvprintw(yVal - 2, xVal + 22, "b");
    mvprintw(yVal - 2, xVal + 33, "c");
    mvprintw(yVal - 2, xVal + 44, "d");

    //print row values
    for (int i = 0; i < 10; i++)
        mvprintw(yVal++, xVal, "%d", i);

    //print cell values
    for (auto itr = std::begin(tmpValues); itr != std::end(tmpValues); itr++) {
        if (nPrinted % 10 == 0) {
            xVal += 11;
            yVal = 6;
        }
        mvprintw(yVal++, xVal, "%d", itr->getValue());
        nPrinted++;
    }

    mvprintw(yOp, xOp - 10, "Max:");
    mvprintw(yOp++, xOp, "%d", max.getMax());
    mvprintw(yOp, xOp - 10, "Min:");
    mvprintw(yOp++, xOp, "%d", min.getMin());
    mvprintw(yOp, xOp - 10, "Sum:");
    mvprintw(yOp++, xOp, "%ld", sum.getSum());
    mvprintw(yOp, xOp - 10, "Mean:");
    mvprintw(yOp, xOp, "%Lf", mean.getMean());

    mvprintw(yLeg++, xLeg - 1, "-Write a value:");
    mvprintw(yLeg++, xLeg, "Press numbers to generate new value");
    mvprintw(yLeg++, xLeg, "Press d to delete the last number of the value");

    mvprintw(yLeg++, xLeg - 1, "-Operation choice:");
    mvprintw(yLeg++, xLeg, "Press a to add a value");
    mvprintw(yLeg++, xLeg, "Press r to remove a value");

    mvprintw(yLeg++, xLeg - 1, "-Press e to exit and show results");
    mvprintw(yLeg, xLeg - 1, "-Press CTRL(CMND)+C to close the window");

    mvprintw(y, x - 10, "New value:");
    mvprintw(y, x, "%d", 0);

    move(y, x + nCifre);

    while (1) {
        int choice = getch();

        switch (choice) {
            case 48:
            case 49:
            case 50:
            case 51:
            case 52:
            case 53:
            case 54:
            case 55:
            case 56:
            case 57:
                if (nCifre == 6) {
                    mvprintw(y, x + nCifre + 3, "WARNING: new value must be shorter than 7 characters!");
                    move(y, x + nCifre);
                    break;
                }
                newValue = (newValue * 10) + (choice - 48);
                mvprintw(y, x, "%d", newValue);
                nCifre++;
                move(y, x + nCifre);
                break;

            case 97:
                if (newValue == 0) {
                    move(y, x + nCifre);
                    break;
                } else {
                    bool added = false;
                    tmpValues = values.getValues();
                    for (auto itr = std::begin(tmpValues); itr != std::end(tmpValues); itr++) {
                        if (itr->getValue() == 0 && !added) {
                            values.addValue(itr->getColumn(), itr->getRow(), newValue);
                            added = true;
                        }
                    }
                    if (!added) {
                        mvprintw(yVal, xVal - 39, "WARNING: the list cannot contain more values!");
                        move(y, x + nCifre);
                        break;
                    }

                    newValue = 0;
                    nCifre = 0;
                    clear();
                    tmpValues = values.getValues();
                    yVal = 6;
                    xVal = 3;
                    //print column values
                    mvprintw(yVal - 2, xVal + 11, "a");
                    mvprintw(yVal - 2, xVal + 22, "b");
                    mvprintw(yVal - 2, xVal + 33, "c");
                    mvprintw(yVal - 2, xVal + 44, "d");
                    //print row values
                    for (int i = 0; i < 10; i++)
                        mvprintw(yVal++, xVal, "%d", i);
                    //print cell values
                    for (auto itr = std::begin(tmpValues); itr != std::end(tmpValues); itr++) {
                        if (nPrinted % 10 == 0) {
                            xVal += 11;
                            yVal = 6;
                        }
                        mvprintw(yVal++, xVal, "%d", itr->getValue());
                        nPrinted++;
                    }

                    yOp = 6;
                    mvprintw(yOp, xOp - 10, "Max:");
                    mvprintw(yOp++, xOp, "%d", max.getMax());
                    mvprintw(yOp, xOp - 10, "Min:");
                    mvprintw(yOp++, xOp, "%d", min.getMin());
                    mvprintw(yOp, xOp - 10, "Sum:");
                    mvprintw(yOp++, xOp, "%ld", sum.getSum());
                    mvprintw(yOp, xOp - 10, "Mean:");
                    mvprintw(yOp, xOp, "%Lf", mean.getMean());

                    yLeg = 20;
                    mvprintw(yLeg++, xLeg - 1, "-Write a value:");
                    mvprintw(yLeg++, xLeg, "Press numbers to generate new value");
                    mvprintw(yLeg++, xLeg, "Press d to delete the last number of the value");

                    mvprintw(yLeg++, xLeg - 1, "-Operation choice:");
                    mvprintw(yLeg++, xLeg, "Press a to add a value");
                    mvprintw(yLeg++, xLeg, "Press r to remove a value");

                    mvprintw(yLeg++, xLeg - 1, "-Press e to exit and show results");
                    mvprintw(yLeg, xLeg - 1, "-Press CTRL(CMND)+C to close the window");

                    mvprintw(y, x - 10, "New value:");
                    mvprintw(y, x, "%d", 0);

                    move(y, x + nCifre);
                    break;
                }

            case 114:
                if (newValue == 0) {
                    break;
                } else {
                    bool removed = false;
                    tmpValues = values.getValues();
                    for (auto itr = std::begin(tmpValues); itr != std::end(tmpValues); itr++) {
                        if (itr->getValue() == newValue && !removed) {
                            values.removeValue(itr->getColumn(), itr->getRow());
                            removed = true;
                        }
                    }

                    newValue = 0;
                    nCifre = 0;
                    clear();
                    tmpValues = values.getValues();
                    yVal = 6;
                    xVal = 3;
                    //print column values
                    mvprintw(yVal - 2, xVal + 11, "a");
                    mvprintw(yVal - 2, xVal + 22, "b");
                    mvprintw(yVal - 2, xVal + 33, "c");
                    mvprintw(yVal - 2, xVal + 44, "d");
                    //print row values
                    for (int i = 0; i < 10; i++)
                        mvprintw(yVal++, xVal, "%d", i);
                    //print cell values
                    for (auto itr = std::begin(tmpValues); itr != std::end(tmpValues); itr++) {
                        if (nPrinted % 10 == 0) {
                            xVal += 11;
                            yVal = 6;
                        }
                        mvprintw(yVal++, xVal, "%d", itr->getValue());
                        nPrinted++;
                    }

                    yOp = 6;
                    mvprintw(yOp, xOp - 10, "Max:");
                    mvprintw(yOp++, xOp, "%d", max.getMax());
                    mvprintw(yOp, xOp - 10, "Min:");
                    mvprintw(yOp++, xOp, "%d", min.getMin());
                    mvprintw(yOp, xOp - 10, "Sum:");
                    mvprintw(yOp++, xOp, "%ld", sum.getSum());
                    mvprintw(yOp, xOp - 10, "Mean:");
                    mvprintw(yOp, xOp, "%Lf", mean.getMean());

                    yLeg = 20;
                    mvprintw(yLeg++, xLeg - 1, "-Write a value:");
                    mvprintw(yLeg++, xLeg, "Press numbers to generate new value");
                    mvprintw(yLeg++, xLeg, "Press d to delete the last number of the value");

                    mvprintw(yLeg++, xLeg - 1, "-Operation choice:");
                    mvprintw(yLeg++, xLeg, "Press a to add a value");
                    mvprintw(yLeg++, xLeg, "Press r to remove a value");

                    mvprintw(yLeg++, xLeg - 1, "-Press e to exit and show results");
                    mvprintw(yLeg, xLeg - 1, "-Press CTRL(CMND)+C to close the window");

                    mvprintw(y, x - 10, "New value:");
                    mvprintw(y, x, "%d", 0);

                    move(y, x + nCifre);

                    break;
                }

            case 100:
                if (nCifre == 0) {
                    move(y, x + nCifre);
                    break;
                }
                if (nCifre == 6) {
                    move(y, x);
                    clrtoeol();
                    nCifre--;
                    newValue = static_cast<int>(newValue / 10);
                    mvprintw(y, x, "%d", newValue);
                    break;
                } else {
                    mvdelch(y, x + nCifre - 1);
                    nCifre--;
                    newValue = static_cast<int>(newValue / 10);
                    mvprintw(y, x, "%d", newValue);
                    move(y, x + nCifre);
                    break;
                }


            case 101:
                endwin();
                std::cout << "SpreadSheet - v." << VERSION << "\n" << std::endl;
                values.printValues();
                std::cout << "Max: " << max.getMax() << std::endl;
                std::cout << "Min: " << min.getMin() << std::endl;
                std::cout << "Mean: " << mean.getMean() << std::endl;
                std::cout << "Sum: " << sum.getSum() << std::endl;
                std::cout << "\nPress CTRL + C to exit" << std::endl;
                break;


            default:
                break;
        }
    }
}