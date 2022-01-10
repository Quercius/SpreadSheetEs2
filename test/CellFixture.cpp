//
// Created by tommi on 10/01/2022.
//

#include <gtest/gtest.h>
#include "../Cell.h"

class CellSuite : public ::testing::Test {
protected:
    Cell c = Cell("a", 0, 10);
};

TEST_F(CellSuite, TestGetters) {
    ASSERT_EQ("a", c.getColumn());
    ASSERT_EQ(0, c.getRow());
    ASSERT_EQ(10, c.getValue());
}

TEST_F(CellSuite, TestSetters) {
    c.setColumn("b");
    c.setRow(2);
    c.setValue(30);
    ASSERT_EQ("b", c.getColumn());
    ASSERT_EQ(2, c.getRow());
    ASSERT_EQ(30, c.getValue());
}