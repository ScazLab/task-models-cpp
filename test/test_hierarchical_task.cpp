#include "gtest/gtest.h"

#include "task-models/task_htm.h"

TEST(testExampleClass, testConstructor)
{
    HierarchicalTask ht("/home/alecive/code/task-models-cpp/test/task-model.js");

    //  ht.printJson();

    json j = ht.getJson();


    SubTask subtasks = parseNode(j);

    ht.getHTM().printSubTask();

    ht.getHTM().printChildren();


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
