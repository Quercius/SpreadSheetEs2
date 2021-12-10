
#include <iostream>
#include <ncurses/ncurses.h>
#include <list>
#include "Values.h"
#include "Operations.h"


int main() {
    std::list<double> vls = {2.432, 4.12345, 5.2205, 501.249, 35.20593};
    Values values(vls);
    Operations operations(&values);
    std::cout << operations.getMax() << std::endl << operations.getMin() << std::endl;


    int newValue = 0;

    initscr();

    noecho();
    int x, y;
    x = 5;
    y = 5;

    int choice = 0;


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
                //values.addValue(newValue);
                newValue = 0;
                mvprintw(y, x, "%d", choice);
                break;

            case 114:
                //values.removeValue(newValue);
                newValue = 0;
                mvprintw(y, x, "%d", choice);
                x = x + 3;
                break;

            case 101:
                endwin();

            default:
                break;

        }

    }


}

