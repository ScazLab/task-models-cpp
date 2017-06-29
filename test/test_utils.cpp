#include "gtest/gtest.h"
#include "utils.h"

using namespace std;
using Eigen::MatrixXd;

TEST(testUtils, isNormal)
{
    MatrixXd testMatrix1(1,1);
    testMatrix1(0,0) = 0.8;
    // default epsilon:
    EXPECT_EQ(isNormal(testMatrix1), false);
    // set a more merciful epsilon:
    EXPECT_EQ(isNormal(testMatrix1, 0.2), true);

    MatrixXd testMatrix2(2,2);
    testMatrix2(0,0) = 0.5;
    testMatrix2(0,1) = 0.3;
    testMatrix2(1,0) = 0.1;
    testMatrix2(1,1) = 0.1;
    EXPECT_EQ(isNormal(testMatrix2), true);

    testMatrix2(1,1) = 0.5;
    EXPECT_EQ(isNormal(testMatrix2), false);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}
