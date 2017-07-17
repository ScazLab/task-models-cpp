#include <string>
#include <map>
#include <set>
#include <iostream>
#include <typeinfo>
#include "json.hpp"
#include <fstream>

using namespace nlohmann;

class HierarchicalTask
{

private:

    json deserialization;

    //for test
    std::string namevalue;

    json children;
    json subchildren;

    json action;

    std::string childrennamevalue;


    //auto childrenarray;
    //std::unordered_map<std::string, json> childrenarray;
    //json children = json::array();

public:

    HierarchicalTask();

    // Returns the JSON Object
    json returnDeserialization();

    // Meant for debugging purposes; prints out
    // deserialization as a serialized json string
    void printJson();

    // Takes the Json object
    // And creates an array of
    // children and actions
    void createTree();

    // write additional functions that allow certain attributes of
    // the json object to be accessed
    // also how to access the children / subattributes
    // look up deep search / deep copy
    // create seperate classes for all the children!

    ~HierarchicalTask() {};
};

// Node is the highest level in the task tree
// (Named "task" in our Task_model_format json file)
class Node
{
protected:
    std::string name;
    std::string type;

public:

    Node(std::string _name, std::string _type);

    void setName(std::string _name);

    void setType(std::string _type);

    void printNode();

};

class SubTask : public Node
{
public:

    std::vector<SubTask> children;

    SubTask(std::string _name, std::string _type);

    void printSubTask();

    void printChildren();

    ~SubTask() {};
};

class Action : public Node
{
public:
    std::string action;

    Action(std::string _name, std::string _type);

    ~Action() {};
};

SubTask parseNode (json j);
