#include <gtest/gtest.h>

int add(int a, int b) {
    return a + b;
}

TEST(MathTest, TwoPlusTwoEqualsFour) {
    EXPECT_EQ(2 + 2, 4);
}

TEST(MathTest, Add) {
    EXPECT_EQ(4, add(2, 2));
    EXPECT_EQ(6, add(2, 4));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}