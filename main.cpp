
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


}

