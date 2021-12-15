
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
    int x, y, xVal, yVal, xOp, yOp;
    x = 3;
    y = 3;
    xVal = 6;
    yVal = 6;
    xOp = 10;
    yOp = 6;

    std::list<int> tmpValues = values.getValues();
    for (auto itr = std::begin(tmpValues); itr != std::end(tmpValues); itr++) {
        mvprintw(yVal++, xVal, "%d", *itr);
    }
    yVal = 6;

    mvprintw(yOp++, xOp, "%d", operations.getMax());
    mvprintw(yOp++, xOp, "%d", operations.getMin());
    mvprintw(yOp++, xOp, "%d", operations.getSum());
    mvprintw(yOp++, xOp, "%f", operations.getMean());
    yOp = 6;

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
                values.addValue(newValue);
                newValue = 0;
                tmpValues = values.getValues();
                yVal = 6;
                for (auto itr = std::begin(tmpValues); itr != std::end(tmpValues); itr++) {
                    mvprintw(yVal++, xVal, "%d", *itr);
                }
                yOp = 6;
                mvprintw(yOp++, xOp, "%d", operations.getMax());
                mvprintw(yOp++, xOp, "%d", operations.getMin());
                mvprintw(yOp++, xOp, "%d", operations.getSum());
                mvprintw(yOp++, xOp, "%f", operations.getMean());
                break;

            case 114:
                values.removeValue(newValue);
                newValue = 0;
                clear();
                tmpValues = values.getValues();
                yVal = 6;
                for (auto itr = std::begin(tmpValues); itr != std::end(tmpValues); itr++) {
                    mvprintw(yVal++, xVal, "%d", *itr);
                }
                yOp = 6;
                mvprintw(yOp++, xOp, "%d", operations.getMax());
                mvprintw(yOp++, xOp, "%d", operations.getMin());
                mvprintw(yOp++, xOp, "%d", operations.getSum());
                mvprintw(yOp++, xOp, "%f", operations.getMean());
                break;

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
