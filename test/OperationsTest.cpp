//
// Created by tommi on 17/12/2021.
//

#include "gtest/gtest.h"
#include "../Values.h"
#include "../Max.h"
#include "../Min.h"
#include "../Mean.h"
#include "../Sum.h"

TEST(Operation, TestConstructor) {
    Values v;
    v.addValue("a", 0, 10);
    Max max = Max(&v);
    Min min = Min(&v);
    Mean mean = Mean(&v);
    Sum sum = Sum(&v);

}
