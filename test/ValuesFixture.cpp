#include "gtest/gtest.h"
#include "../Values.h"
#include "../Max.h"
#include "../Min.h"
#include "../Mean.h"
#include "../Sum.h"

class ValuesSuite : public ::testing::Test {
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


TEST_F(ValuesSuite, TestAddValue) {
    v.addValue("a", 1, 20);
    ASSERT_EQ(20, (++std::begin(v.getValues()))->getValue());
}

TEST_F(ValuesSuite, TestRemoveValue) {
    v.removeValue("a", 0);
    ASSERT_EQ(0, std::begin(v.getValues())->getValue());
}

/*TEST_F(ValuesSuite, TestUpdate) {
    v.addValue(20);
    v.addValue(30);
    ASSERT_EQ(3, op.getOpValues().size());
}*/

TEST_F(ValuesSuite, TestUnsubscribe) {
    v.unsubscribe(&max);
    ASSERT_EQ(3, v.getObserver().size());
}

TEST_F(ValuesSuite, TestGetValues) {
    ASSERT_EQ(10, std::begin(v.getValues())->getValue());
}