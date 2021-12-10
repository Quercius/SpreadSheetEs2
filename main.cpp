
#include <iostream>
#include <ncurses/ncurses.h>
#include <list>
#include "Values.h"
#include "Operations.h"


int main() {
    std::list<int> vls = {2, 43, 1234, 45, 765, 3, 654};
    Values values(vls);
    Operations operations(&values);
    values.addValue(1);
    std::cout << "Max: " << operations.getMax() << std::endl << "Min: " << operations.getMin() << std::endl;

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

