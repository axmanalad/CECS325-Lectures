#include <gtest/gtest.h>
#include "factorial.h"

TEST(F, BasicAssertions) {
    EXPECT_EQ(1, 2 >> 1);
}
TEST(F, BasicAssertions2) {
    EXPECT_EQ(120, factorial(5));
}
