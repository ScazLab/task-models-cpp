#include "gtest/gtest.h"

#include "task-models/supportive_pomdp_state.h"

TEST(testSupportivePOMPDstate, testAssistantMethods)
{
    SupportiveState supportstate(5, 3, 2, 4);

}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}
