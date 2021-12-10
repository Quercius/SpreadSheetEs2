
#include <iostream>
#include <ncurses/ncurses.h>
#include <list>
#include "Values.h"
#include "Operations.h"


int main() {
    std::list<int> vls = {2, 43, 1234, 45, 765, 3, 654};
    Values values(vls);
    Operations operations(&values);
    std::cout << operations.getMax() << std::endl << operations.getMin() << std::endl;



}

