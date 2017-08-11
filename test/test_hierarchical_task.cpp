#include "gtest/gtest.h"

#include "task-models/task_htm.h"

/*
Some notes: clean up and add function documentation
make some of the variables that are currently public private
and access them using getter/setter functions

For testing the json write out a new json file
then take this json, convert it using what you have so far
then turn the converted json into a string using a new function 
then do a string comparsion (compare this string to a manually typed out string
of the json object you make)

Some additional notes

Write a way to add a subtask / action to the children vector that holds all the states and actions. 
Then also add that subtask / action to the actual json file
and save it. Add tests for this (best way to do it is create a json file j1 , then create 
another json file that is almost like it, j2 - then modify j2 to be j1 using the new way you 
implemented. Compare that the two files are identical)

Best way to allow modification is probably taking in a string input or something from the user (ask Alessandro!) 
 */

TEST(testClasses, testDefaultPrintandFile)
{
    HierarchicalTask ht("/home/andrew/Desktop/task-models-cpp/test/task-model.js");
    //HierarchicalTask ht("./task-model.js");

    json j = ht.getJson();

    SubTask* subtask = dynamic_cast<SubTask*>(ht.getHTM());

    std::cout << "\n";
    // We changed this to private so it is no longer accessible
    // Write a getter function that returns the subtask children!
    // std::cout << "The size of the children vector is: " << subtask->children.size() << std::endl;
    std::cout << "\n";
    
    subtask->print();
}

TEST(testClasses, testParseNode)
{
    HierarchicalTask ht("/home/andrew/Desktop/task-models-cpp/test/test_json.js");
    //HierarchicalTask ht("./task-model.js");

    json j = ht.getJson();
    std::string jsonstring = j.dump();

    SubTask* subtask = dynamic_cast<SubTask*>(ht.getHTM());

    std::cout << jsonstring << std::endl;

    subtask->print(); 
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}

// String of the test_json object
// {"children":[{"children":[{"action":{"conditions":[["uses","joints"],["uses","screws"],["uses","screwdriver"],["consumes","leg"],["support","hold-h"]]},"name":"assemble leg-1","type":"leaf"}],"name":"first leg","type":"sequential"}],"name":"task","type":"sequential"}
