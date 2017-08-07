#include "gtest/gtest.h"

#include "example-lib/exampleClass.h"

TEST(testExampleClass, testConstructor)
{
    exampleClass ec;

    EXPECT_EQ(ec.getVal(), 10) << "ec.getVal() " << ec.getVal() << std::endl;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}
