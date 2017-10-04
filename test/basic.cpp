#include "gtest/gtest.h"

int add(int a, int b) {
    return a + b;
}

TEST(testMath, myCubeTest) {
    EXPECT_EQ(13, add(3, 10));
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}