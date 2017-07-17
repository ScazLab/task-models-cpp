#include <string>
#include <map>
#include <set>
#include <iostream>
#include <typeinfo>
#include "json.hpp"
#include <fstream>


#include <unordered_map>
/* 
    For the path, have two seperate objects: the state, and the action
    Put these two together into one structure
    Then the path will be composed of that structure / reference the objects in that structure
    In checkpath, you will then check that the state and action objects are
    in the correct order
*/

/*  
    Transitions (s, l, d) are stored as {s: {(l, d), ...}, ...}, that is
    a dictionary of sets of pairs.

    s (source state) is the KEY to a VALUE that is of type Set

    Each set is composed of PAIRS that are l, d
*/

typedef std::pair <std::string, std::string> Point;
typedef std::set <Point> List;

using namespace nlohmann;

/*
bool checkpath(std::set<std::string> _path)
{
    if (_path.size() == 0)
    {
        return true;
    }

    if (_path )
    {

    }

    return false;
} */

// create a recursive function that keeps searching for children 
// and keeps returning children as it goes through the json file
// refer to the photo that was taken




class BaseGraph
{
private:
    //std::map<int, std::pair<std::string, std::string>> transitions;
    std::map<std::string, std::set<std::pair<std::string, std::string>>> transitions;


public:
    BaseGraph();

    bool equality(BaseGraph _basegraph, BaseGraph _basegraph1);

    void addTransition(std::string _source, std::string _label, std::string _destination);

    List hasTransition(std::string _source, std::string _label, std::string _destination);

    // all_transitions(); //not needed for now

    std::set<std::string> allNodes();

    // for now, a name is not returned when this function is called
    std::map<std::string, std::set<std::pair<std::string, std::string>>> asDictionary(std::string _name);

    ~BaseGraph();
};
/*
class Taskgraph : public BaseGraph
{
private:
    std::set<std::string> intial;
    std::set<std::string> terminal;

public:
    explicit Taskgraph();

    bool equality(Taskgraph _taskgraph, Taskgraph _taskgraph1);

    void addPath();


    // return true if exception is raised; false otherwise
    // cout an exception if an exception is raised
    bool hasPath();

    bool checkOnlyDeterministicTransitionsFromState();

    bool checkOnlyDeterministicTransitions();

    bool conjugate();
}; */
//store the state and actions in their own array as they are created

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
