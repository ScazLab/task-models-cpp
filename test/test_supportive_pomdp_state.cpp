#include "gtest/gtest.h"

#include "task-models/supportive_pomdp_state.h"
#include <algorithm>

/*
TEST(testSupportivePOMPDstate, testDebugging)
{
    SupportiveState supportstate(5, 3, 2, 4);

    EXPECT_EQ(supportstate.shiftbody, 4);
    EXPECT_EQ(supportstate.shiftpref, 6);
    EXPECT_EQ(supportstate.shifthtm, 9);
    EXPECT_EQ(supportstate.finalhtm, (5-1));
    EXPECT_EQ(supportstate.s, 0);
} */

TEST(testSupportivePOMPDstate, testSetGetHTM)
{
    SupportiveState supportstate(5, 3, 2, 4);
    EXPECT_EQ(supportstate.getHTM(), 0);

    for (int i = 0; i < 3; i++)
    {
        supportstate.setPreferences(i, 1);
    }

    for (int i = 0; i < 2; i++)
    {
        supportstate.setBodyFeatures(i, 1);
    }

    for (int i = 0; i < 4; i++)
    {
        supportstate.setObject(i,1);
    }

    EXPECT_EQ(supportstate.getHTM(), 0);
    supportstate.setHTM(3);
    EXPECT_EQ(supportstate.getHTM(), 3);

}

TEST(testSupportivePOMPDstate, testSetGetPreferences)
{
    SupportiveState supportstate(5, 3, 2, 4);

    for (int i = 0; i < 3; i++)
    {
        EXPECT_EQ(supportstate.hasPreferences(i), 0);
    }

    supportstate.setHTM(3);
    
    for (int i = 0; i < 2; i++)
    {
        supportstate.setBodyFeatures(i, 1);
    }

    for (int i = 0; i < 4; i++)
    {
        supportstate.setObject(i, 1);
    } 

    for (int i = 0; i < 3; i++)
    {
        EXPECT_EQ(supportstate.hasPreferences(i), 0);
    } 

    for (int i = 0; i < 3; i++)
    {
        EXPECT_EQ(supportstate.hasPreferences(i), 0);
        supportstate.setPreferences(i, i % 2);
        EXPECT_EQ(supportstate.hasPreferences(i), i % 2);
    }
}

TEST(testSupportivePOMPDstate, testSetGetBodyFeatures)
{
    SupportiveState supportstate(5, 3, 2, 4);

    for (int i = 0; i < 2; i++)
    {
        EXPECT_EQ(supportstate.hasBodyFeatures(i), 0);
    }
    supportstate.setHTM(3);

    for (int i = 0; i < 3; i++)
    {
        supportstate.setPreferences(i, 1);
    }

    for (int i = 0; i < 4; i++)
    {
        supportstate.setObject(i, 1);
    }

    for (int i = 0; i < 2; i++)
    {
        EXPECT_EQ(supportstate.hasBodyFeatures(i), 0);
    }

    for (int i = 0; i < 2; i++)
    {
        EXPECT_EQ(supportstate.hasBodyFeatures(i), 0);
        supportstate.setBodyFeatures(i, i % 2);
        EXPECT_EQ(supportstate.hasBodyFeatures(i), i % 2);
    }
}

TEST(testSupportivePOMPDstate, testSetGetObject)
{
    SupportiveState supportstate(5, 3, 2, 4);

    for (int i = 0; i < 4; i++)
    {
        EXPECT_EQ(supportstate.getObject(i), 0);  
    }

    supportstate.setHTM(3); 

    for (int i = 0; i < 2; i++)
    {
        supportstate.setBodyFeatures(i, 1);
    }

    for (int i = 0; i < 3; i++)
    {
        supportstate.setPreferences(i, 1);
    }

    for (int i = 0; i < 4; i++)
    {
        EXPECT_EQ(supportstate.getObject(i), 0);
    }

    for (int i = 0; i < 4; i++)
    {
        EXPECT_EQ(supportstate.getObject(i), 0);
        supportstate.setObject(i, i % 2);
        EXPECT_EQ(supportstate.getObject(i), i % 2);
    }
}

TEST(testSupportivePOMPDstate, testString)
{
    SupportiveState supportstate(5, 3, 2, 4);

    supportstate.setHTM(3);

    for (int i = 0; i < 3; i++)
    {
        supportstate.setPreferences(i, i % 2);
    }   

    for (int i = 0; i < 2; i++)
    {
        supportstate.setBodyFeatures(i, i % 2);
    }

    for (int i = 0; i < 4; i++)
    {
        supportstate.setObject(i, (i+1) % 2);
    }

    EXPECT_EQ(supportstate.suppString(), "1701: 3 010 01 1010");
}

TEST(testSupportivePOMPDstate, testIsFinal)
{
    SupportiveState supportstate(5, 3, 2, 4);

    supportstate.setHTM(3);
    EXPECT_FALSE(supportstate.isFinal());
    supportstate.setHTM(4);
    EXPECT_TRUE(supportstate.isFinal()); 
}

TEST(testSupportivePOMPDstate, testBeliefHTM)
{
    SupportiveState supportstate(3, 1, 1, 2);
    std::vector<double> array (3*pow(2,4), 0.0);

    // bq[0] = .3
    array[supportstate.toInt()] = .1;
    supportstate.setObject(0,1);
    array[supportstate.toInt()] = .1;
    supportstate.setObject(1,1);
    array[supportstate.toInt()] = .1;

    // bq[2] = .7
    supportstate.setInt(0);
    supportstate.setHTM (2);
    array[supportstate.toInt()] = .3;
    supportstate.setPreferences(0,1);
    array[supportstate.toInt()] = .4;


    std::vector<double> result         = supportstate.beliefHTM(array);
    std::vector<double> expectedresult = {0.3, 0.0, 0.7};
    
    for (unsigned int i = 0; i < result.size(); i++)
    {
        EXPECT_DOUBLE_EQ(result[i], expectedresult[i]);
    }
   
   //The output of the function matches the expected output
    std::cout << " The resulting vector from beliefHTM" << std::endl;
    for (unsigned int i = 0; i < result.size(); i++)
    {
        std::cout << "The value of the result vector at " << i << " is : " << result[i] << std::endl;
    }

}

TEST(testSupportivePOMPDstate, testBeliefPreferences)
{
    //not working; fix!
    SupportiveState supportstate(3, 2, 1, 2);

    std::vector<double> array(3*pow(2,5), 0.0);

    //this for loop is for debugging
    for (unsigned int i = 0; i < array.size(); i++)
    {
        //std::cout<< array[i] << std::endl;
    }

    // bp[00, 01, 10, 11] = .1 .1 0. .2
    array[supportstate.toInt()] = .1;
    supportstate.setObject(0,1);
    supportstate.setPreferences(1,1);
    array[supportstate.toInt()] = .1;
    supportstate.setObject(1,1);
    supportstate.setPreferences(0,1);
    array[supportstate.toInt()] = .2;

    // 
    /*
    int leng = supportstate.beliefPreferences(array).size();
    for (int i = 0; i < leng; i++)
    {
        std::cout << array[i] << " " << supportstate.beliefPreferences(array)[i] << std::endl;
    }
    */
    //

    // bp[00, 01, 10, 11] = .3 0. .4 0.
    supportstate.setInt(0);
    supportstate.setHTM(2);
    array[supportstate.toInt()] = .3;
    supportstate.setPreferences(0,1);
    array[supportstate.toInt()] = .4;

    int length = supportstate.beliefPreferences(array).size();
    EXPECT_EQ(length,2);

    //test the arrays here; we need to test if the are approx. equal
    //in gtest, there is an acceptable error bound - make sure the
    //error you choose is correct for this test
    //
    //EXPECT_NEAR(val1, val2, abs_error);
    //
    //For now, I just print the values
    
    for (int i = 0; i < length - 1; i++)
    {
        //std::cout << array[i] << " " << supportstate.beliefPreferences(array)[i] << std::endl;
        //std::cout << supportstate.beliefPreferences(array)[i] << " " << supportstate.beliefPreferences(array)[i+1] << std::endl;
    }

    std::cout << "For debugging: " << std::endl;

    for (int i = 0; i < 96; i++)
    {
       //std::cout << array[i] << std::endl;
    }
}

TEST(testSupportivePOMPDstate, testRandomObjectChanges)
{
    SupportiveState supportstate(5, 3, 2, 4);

    supportstate.setHTM(2);
    supportstate.setObject(1,1);
    supportstate.setObject(3,1);
    supportstate.setPreferences(1,1);
    supportstate.setBodyFeatures(0,1);

    supportstate.randomObjectChanges(0);
    std::string teststring1 = supportstate.suppString().substr(6,18);
    EXPECT_EQ(teststring1, "2 010 10 0101");

    supportstate.randomObjectChanges(1);
    std::string teststring2 = supportstate.suppString().substr(6,18);
    EXPECT_EQ(teststring2, "2 010 10 1010");

    std::cout << "Test String 1: " << teststring1 << std::endl;
    std::cout << "Test String 2: " << teststring2 << std::endl;
}

TEST(testSupportivePOMPDstate, testRandomPreferenceChanges)
{
    SupportiveState supportstate(5, 3, 2, 4);

    supportstate.setHTM(2);
    supportstate.setObject(1,1);
    supportstate.setObject(3,1);
    supportstate.setPreferences(1,1);
    supportstate.setBodyFeatures(0,1);

    supportstate.randomPreferenceChanges(0);
    std::string teststring1 = supportstate.suppString().substr(6,18);
    EXPECT_EQ(teststring1, "2 010 10 0101");
   
    supportstate.randomPreferenceChanges(1);
    std::string teststring2 = supportstate.suppString().substr(6,18);
    EXPECT_EQ(teststring2, "2 101 10 0101");

    std::cout << "Test String 1: " << teststring1 << std::endl;
    std::cout << "Test String 2: " << teststring2 << std::endl;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}
