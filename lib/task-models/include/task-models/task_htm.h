#include <string>
#include <map>
#include <set>
#include <iostream>
#include <typeinfo>
#include "json.hpp"
#include <fstream>

using namespace nlohmann;

// Node is the highest level in the task tree
// (Named "task" in our Task_model_format json file)
class Node
{
protected:
    std::string name;
    std::string type;

public:

    /**
     * Empty Constructor
     */
    Node() {};

    Node(std::string _name, std::string _type);

    void setName(std::string _name);

    void setType(std::string _type);

    void printNode();

};

class SubTask : public Node
{
public:

    std::vector<SubTask> children;

    /**
     * Empty Constructor
     */
    SubTask() {};

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

class HierarchicalTask
{

private:

    json json_obj;

    SubTask   htm;

public:

    /**
     * Empty constructor
     */
    HierarchicalTask();

    /**
     * Constructor that takes as input a hierarchical network as json file.
     *
     * @param _filename the input htm in json format
     */
    HierarchicalTask(std::string _filename);

    // Returns the JSON Object
    json getJson()          { return json_obj; };

    /**
     * Returns the HTM (if any).
     *
     * @return the HTM
     */
    SubTask getHTM()        { return      htm; };

    // Meant for debugging purposes; prints out
    // deserialization as a serialized json string
    void printJson();

    // write additional functions that allow certain attributes of
    // the json object to be accessed
    // also how to access the children / subattributes
    // look up deep search / deep copy
    // create seperate classes for all the children!

    ~HierarchicalTask() {};
};

SubTask parseNode (json j);
