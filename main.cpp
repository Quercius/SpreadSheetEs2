
#include <iostream>
#include <ncurses/ncurses.h>
#include <list>
#include "Values.h"
#include "Operations.h"


int main() {
    std::list<int> vls = {2, 3};
    Values values(vls);
    Operations operations(&values);
    values.addValue(1);
    std::cout << "Max: " << operations.getMax() << std::endl << "Min: " << operations.getMin() << std::endl;

    int newValue = 0;


    initscr();

    noecho();
    int x, y, xVal, yVal, xOp, yOp, xLeg, yLeg;
    x = 15;
    y = 3;
    xVal = 6;
    yVal = 6;
    xOp = 40;
    yOp = 6;
    xLeg = 5;
    yLeg = 22;

    std::list<int> tmpValues = values.getValues();
    for (auto itr = std::begin(tmpValues); itr != std::end(tmpValues); itr++) {
        mvprintw(yVal++, xVal, "%d", *itr);
    }
    yVal = 6;

    mvprintw(yOp, xOp - 10, "Max:");
    mvprintw(yOp++, xOp, "%d", operations.getMax());
    mvprintw(yOp, xOp - 10, "Min:");
    mvprintw(yOp++, xOp, "%d", operations.getMin());
    mvprintw(yOp, xOp - 10, "Sum:");
    mvprintw(yOp++, xOp, "%d", operations.getSum());
    mvprintw(yOp, xOp - 10, "Mean:");
    mvprintw(yOp++, xOp, "%f", operations.getMean());
    yOp = 6;
    mvprintw(y, x - 10, "New value:");
    mvprintw(yLeg++, xLeg, "Press numbers to generate new value");
    mvprintw(yLeg++, xLeg, "Press a to add the new value");
    mvprintw(yLeg++, xLeg, "Press r to remove the new value");
    mvprintw(yLeg++, xLeg, "Press e to exit and show results");
    mvprintw(yLeg++, xLeg, "Press CTRL(CMND)+C to close the window");

    int choice = 0;

    //show values and operations


    while (1) {
        int choice = getch();

        switch (choice) {
            case 48:
                newValue = (newValue * 10) + (choice - 48);
                mvprintw(y, x, "%d", newValue);
                break;


            case 49:
                newValue = (newValue * 10) + (choice - 48);
                mvprintw(y, x, "%d", newValue);
                break;

            case 50:
                newValue = (newValue * 10) + (choice - 48);
                mvprintw(y, x, "%d", newValue);
                break;

            case 51:
                newValue = (newValue * 10) + (choice - 48);
                mvprintw(y, x, "%d", newValue);
                break;

            case 52:
                newValue = (newValue * 10) + (choice - 48);
                mvprintw(y, x, "%d", newValue);
                break;

            case 53:
                newValue = (newValue * 10) + (choice - 48);
                mvprintw(y, x, "%d", newValue);
                break;

            case 54:
                newValue = (newValue * 10) + (choice - 48);
                mvprintw(y, x, "%d", newValue);
                break;

            case 55:
                newValue = (newValue * 10) + (choice - 48);
                mvprintw(y, x, "%d", newValue);
                break;

            case 56:
                newValue = (newValue * 10) + (choice - 48);
                mvprintw(y, x, "%d", newValue);
                break;

            case 57:
                newValue = (newValue * 10) + (choice - 48);
                mvprintw(y, x, "%d", newValue);
                break;

            case 97:
                if (newValue == 0)
                    break;
                else {
                    values.addValue(newValue);
                    newValue = 0;
                    clear();
                    tmpValues = values.getValues();
                    yVal = 6;
                    for (auto itr = std::begin(tmpValues); itr != std::end(tmpValues); itr++) {
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
                    mvprintw(yOp++, xOp, "%f", operations.getMean());

                    yLeg = 22;
                    mvprintw(y, x - 10, "New value:");
                    mvprintw(yLeg++, xLeg, "Press numbers to generate new value");
                    mvprintw(yLeg++, xLeg, "Press a to add the new value");
                    mvprintw(yLeg++, xLeg, "Press r to remove the new value");
                    mvprintw(yLeg++, xLeg, "Press e to exit and show results");
                    mvprintw(yLeg++, xLeg, "Press CTRL(CMND)+C to close the window");
                    break;
                }

            case 114:
                if (newValue == 0) {
                    break;
                } else {
                    values.removeValue(newValue);
                    newValue = 0;
                    clear();
                    tmpValues = values.getValues();
                    yVal = 6;
                    for (auto itr = std::begin(tmpValues); itr != std::end(tmpValues); itr++) {
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
                    mvprintw(yOp++, xOp, "%f", operations.getMean());

                    yLeg = 22;
                    mvprintw(y, x - 10, "New value:");
                    mvprintw(yLeg++, xLeg, "Press numbers to generate new value");
                    mvprintw(yLeg++, xLeg, "Press a to add the new value");
                    mvprintw(yLeg++, xLeg, "Press r to remove the new value");
                    mvprintw(yLeg++, xLeg, "Press e to exit and show results");
                    mvprintw(yLeg++, xLeg, "Press CTRL(CMND)+C to close the window");
                    break;
                }

            case 115:
                break;

            case 101:
                endwin();
                values.printValues();
                break;


            default:
                break;

        }
    }
}
