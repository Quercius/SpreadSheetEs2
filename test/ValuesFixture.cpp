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


    class tmpObs : public Observer {
    public:
        tmpObs(Values *v) : subj(v) {
            subj->subscribe(this);
        }

        void update() {
            count++;
        }

        int count = 0;
        Values *subj;
    };
};


TEST_F(ValuesSuite, TestAddValue) {
    v.addValue("a", 1, 20);
    ASSERT_EQ(20, (++std::begin(v.getValues()))->getValue());
}

TEST_F(ValuesSuite, TestRemoveValue) {
    v.removeValue("a", 0);
    ASSERT_EQ(0, std::begin(v.getValues())->getValue());
}

TEST_F(ValuesSuite, TestNotify) {
    tmpObs tmpobs = tmpObs(&v);
    v.addValue("b", 2, 10);
    ASSERT_EQ(1, tmpobs.count);
    v.addValue("c", 6, 10);
    ASSERT_EQ(2, tmpobs.count);
}

TEST_F(ValuesSuite, TestUnsubscribe) {
    v.unsubscribe(&max);
    ASSERT_EQ(3, v.getObserver().size());
}

TEST_F(ValuesSuite, TestGetValues) {
    ASSERT_EQ(10, std::begin(v.getValues())->getValue());
}