#include "gtest/gtest.h"

#include "task-models/task_htm.h"

TEST(testExampleClass, testConstructor)
{
    //printf("asodfij\n");
    HierarchicalTask ht;
    //printf("acjajc\n");
    
    //  ht.printJson();

    json j = ht.returnDeserialization();


    SubTask subtasks = parseNode(j);
   
    subtasks.printSubTask();

    subtasks.printChildren();


    //std::vector<SubTask> subtasks;
    //subtasks = parseNode(j);


/*
    printf((j.is_null()) ?"true \n":"false \n");
    printf((j.is_number()) ?"true \n":"false \n");
    printf((j.is_boolean()) ?"true \n":"false \n");
    printf((j.is_object()) ?"true \n":"false \n");
    printf((j.is_array()) ?"true \n":"false \n");
    printf((j.is_string()) ?"true \n":"false \n");

    std::cout << j.size() << std::endl;

    // boolean value; returns 1 or 0
    std::cout << j.empty() << std::endl;
    
    // std::cout << j.type() << std::endl;
    // std::cout << j.clear() << std::endl;
   
    j.size();     // 3 entries
    j.empty();    // false
    j.type();     // json::value_t::array
    j.clear();    // the array is empty again
*/
    
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}