
#include <iostream>
#include <ncurses/ncurses.h>
#include <list>
#include "Values.h"
#include "Operations.h"


int main() {
    std::list<int> vls = {};
    Values values(vls);
    Operations operations(&values);

    int newValue = 0;

    initscr();

    noecho();
    int x, y, xVal, yVal, xOp, yOp, xLeg, yLeg;
    x = 15;
    y = 3;
    xVal = 6;
    yVal = 6;
    xOp = 80;
    yOp = 6;
    xLeg = 5;
    yLeg = 22;

    mvprintw(yVal - 1, xVal, "List:");
    std::list<int> tmpValues = values.getValues();
    for (auto itr = std::begin(tmpValues); itr != std::end(tmpValues); itr++) {
        mvprintw(yVal++, xVal, "%d", *itr);
    }

    mvprintw(yOp, xOp - 10, "Max:");
    mvprintw(yOp++, xOp, "%d", operations.getMax());
    mvprintw(yOp, xOp - 10, "Min:");
    mvprintw(yOp++, xOp, "%d", operations.getMin());
    mvprintw(yOp, xOp - 10, "Sum:");
    mvprintw(yOp++, xOp, "%d", operations.getSum());
    mvprintw(yOp, xOp - 10, "Mean:");
    mvprintw(yOp, xOp, "%f", operations.getMean());

    mvprintw(y, x - 10, "New value:");
    mvprintw(yLeg++, xLeg, "Press numbers to generate new value");
    mvprintw(yLeg++, xLeg, "Press d to delete the last number of the new value");
    mvprintw(yLeg++, xLeg, "Press a to add the new value");
    mvprintw(yLeg++, xLeg, "Press r to remove the new value");
    mvprintw(yLeg++, xLeg, "Press e to exit and show results");
    mvprintw(yLeg, xLeg, "Press CTRL(CMND)+C to close the window");

    int nCifre = 0;

    //show values and operations


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
                if (nCifre == 9) {
                    mvprintw(y, x + nCifre + 3, "WARNING: new value must be shorter than 10 characters!");
                    break;
                }
                newValue = (newValue * 10) + (choice - 48);
                mvprintw(y, x, "%d", newValue);
                nCifre++;
                break;

            case 97:
                if (newValue == 0)
                    break;
                else {
                    values.addValue(newValue);
                    newValue = 0;
                    nCifre = 0;
                    clear();
                    tmpValues = values.getValues();
                    yVal = 6;
                    xVal = 6;
                    mvprintw(yVal - 1, xVal, "List:");
                    int count = 0;
                    for (auto itr = std::begin(tmpValues); itr != std::end(tmpValues); itr++) {
                        count++;
                        if (count == 44) {
                            mvprintw(yVal++, xVal, "%d", *itr);
                            mvprintw(yVal, xVal, "WARNING: the list cannot contain more values!");
                            break;
                        }
                        if (count == 12 || count == 23 || count == 34) {
                            yVal = 6;
                            xVal += 14;
                        }
                        mvprintw(yVal++, xVal, "%d", *itr);
                    }
                    yOp = 6;
                    mvprintw(yOp, xOp - 10, "Max:");
                    mvprintw(yOp++, xOp, "%d", operations.getMax());
                    mvprintw(yOp, xOp - 10, "Min:");
                    mvprintw(yOp++, xOp, "%d", operations.getMin());
                    mvprintw(yOp, xOp - 10, "Sum:");
                    mvprintw(yOp++, xOp, "%d", operations.getSum());
                    mvprintw(yOp, xOp - 10, "Mean:");
                    mvprintw(yOp, xOp, "%f", operations.getMean());

                    yLeg = 22;
                    mvprintw(y, x - 10, "New value:");
                    mvprintw(yLeg++, xLeg, "Press numbers to generate new value");
                    mvprintw(yLeg++, xLeg, "Press d to delete the last number of the new value");
                    mvprintw(yLeg++, xLeg, "Press a to add the new value");
                    mvprintw(yLeg++, xLeg, "Press r to remove the new value");
                    mvprintw(yLeg++, xLeg, "Press e to exit and show results");
                    mvprintw(yLeg, xLeg, "Press CTRL(CMND)+C to close the window");
                    break;
                }

            case 114:
                if (newValue == 0) {
                    break;
                } else {
                    values.removeValue(newValue);
                    newValue = 0;
                    nCifre = 0;
                    clear();
                    tmpValues = values.getValues();
                    yVal = 6;
                    xVal = 6;
                    mvprintw(yVal - 1, xVal, "List:");
                    int count = 0;
                    for (auto itr = std::begin(tmpValues); itr != std::end(tmpValues); itr++) {
                        mvprintw(yVal++, xVal, "%d", *itr);
                        count++;
                        if (count == 12 || count == 23 || count == 34) {
                            yVal = 6;
                            xVal += 14;
                        }
                    }
                    yOp = 6;
                    mvprintw(yOp, xOp - 10, "Max:");
                    mvprintw(yOp++, xOp, "%d", operations.getMax());
                    mvprintw(yOp, xOp - 10, "Min:");
                    mvprintw(yOp++, xOp, "%d", operations.getMin());
                    mvprintw(yOp, xOp - 10, "Sum:");
                    mvprintw(yOp++, xOp, "%d", operations.getSum());
                    mvprintw(yOp, xOp - 10, "Mean:");
                    mvprintw(yOp, xOp, "%f", operations.getMean());

                    yLeg = 22;
                    mvprintw(y, x - 10, "New value:");
                    mvprintw(yLeg++, xLeg, "Press numbers to generate new value");
                    mvprintw(yLeg++, xLeg, "Press d to delete the last number of the new value");
                    mvprintw(yLeg++, xLeg, "Press a to add the new value");
                    mvprintw(yLeg++, xLeg, "Press r to remove the new value");
                    mvprintw(yLeg++, xLeg, "Press e to exit and show results");
                    mvprintw(yLeg, xLeg, "Press CTRL(CMND)+C to close the window");
                    break;
                }

            case 100:
                if (nCifre == 0) {
                    break;
                } else {
                    mvdelch(y, x + nCifre - 1);
                    nCifre--;
                    if (nCifre == 0) {
                        break;
                    }
                    newValue = static_cast<int>(newValue / 10);
                    mvprintw(y, x, "%d", newValue);
                    break;
                }

            case 101:
                endwin();
                values.printValues();
                operations.printOperations();
                std::cout << "\nPress CTRL + C to exit" << std::endl;
                break;


            default:
                break;

        }
    }
}
