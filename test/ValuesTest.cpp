//
// Created by tommi on 17/12/2021.
//

#include "gtest/gtest.h"
#include "../Values.h"
#include "../Max.h"
#include "../Min.h"
#include "../Mean.h"
#include "../Sum.h"

TEST(Values, TestSubscribe) {
    Values v;
    Max max = Max(&v);
    Min min = Min(&v);
    Mean mean = Mean(&v);
    Sum sum = Sum(&v);

    ASSERT_EQ(4, v.getObserver().size());
}