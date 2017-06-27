#include "gtest/gtest.h"

TEST(testExample, testWhatever)
{
    EXPECT_TRUE(true);
    EXPECT_TRUE(false);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}
