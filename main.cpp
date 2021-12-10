
#include <iostream>
#include <ncurses/ncurses.h>
#include <list>
#include "Values.h"
#include "Operations.h"


int main() {
    std::list<double> vls = {2.432, 4.12345, 5.2205, 501.249, 35.20593};
    Values values(vls);
    Operations operations = Operations(&values);
    std::cout << operations.getMax() << std::endl << operations.getMin() << std::endl;
    return 0;
}

