//
// Created by tommi on 10/01/2022.
//

#include "gtest/gtest.h"
#include "../Cell.h"

TEST(Cell, TestConstructor) {
    Cell c = Cell("d", 2, 10);
    ASSERT_EQ("d", c.getColumn());
    ASSERT_EQ(2, c.getRow());
    ASSERT_EQ(10, c.getValue());
}