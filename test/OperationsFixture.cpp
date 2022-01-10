//
// Created by tommi on 17/12/2021.
//

#include "gtest/gtest.h"
#include "../Values.h"
#include "../Max.h"
#include "../Min.h"
#include "../Mean.h"
#include "../Sum.h"

class OperationsSuite : public ::testing::Test {
protected:
    virtual void SetUp() {
        v.addValue("a", 0, 10);
    }

    Values v = Values();
    Max max = Max(&v);
    Min min = Min(&v);
    Mean mean = Mean(&v);
    Sum sum = Sum(&v);
};

TEST_F(OperationsSuite, TestUpdate) {
    v.addValue("a", 1, 20);
    ASSERT_EQ(20, (++std::begin(max.getOpValues()))->getValue());
    ASSERT_EQ(20, (++std::begin(min.getOpValues()))->getValue());
    ASSERT_EQ(20, (++std::begin(mean.getOpValues()))->getValue());
    ASSERT_EQ(20, (++std::begin(sum.getOpValues()))->getValue());
}

TEST_F(OperationsSuite, TestGetters) {
    ASSERT_EQ(10, max.getMax());
    ASSERT_EQ(10, min.getMin());
    ASSERT_EQ(10.0, mean.getMean());
    ASSERT_EQ(10, sum.getSum());
    ASSERT_EQ(&v, max.getSubject());
    ASSERT_EQ(std::begin(max.getOpValues())->getValue(), 10);
}

TEST_F(OperationsSuite, TestCompute) {
    v.addValue("a", 1, 20);
    ASSERT_EQ(20, max.getMax());
    ASSERT_EQ(10, min.getMin());
    ASSERT_EQ(15.0, mean.getMean());
    ASSERT_EQ(30, sum.getSum());
}

