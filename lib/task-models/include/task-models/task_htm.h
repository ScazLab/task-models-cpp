#include <string>
#include <map>
#include <set>
#include <iostream>
#include <typeinfo>
#include "json.hpp"
#include <fstream>

using namespace nlohmann;


class Node
{
protected:
    std::string name;
    std::string type;

public:

    /**
     * Default Empty Constructor
     */
    Node() {};

    /**
     * Constructor
     *
     * @param _name of node
     * @param _type of node
     */
    Node(std::string _name, std::string _type);

    /**
    *Sets the name of the node
    *
    *@param string _name
    */
    void setName(std::string _name);

    /**
     * Sets the type of the node
     * @param _type the type of node
     */
    void setType(std::string _type);

    /**
     * Returns Name of node
     */
    std::string getName()       { return name; };

    /**
     * Returns Type of node
     */
    std::string getType()       { return type; };

    /**
     * Virtual print function to be declared in children
     * Prints name and type of node
     */
    virtual void print();

    /**
     * Virtual Deconstructor 
     */
    virtual ~Node() {};

};

class SubTask : public Node
{
private:

    std::vector<Node*> children;
   // std::vector<Node*> statevector;
   // std::vector<Node*> actionvector;

    /**
     * Prints the vector children
     */
    void printChildren();

public:

    /**
     * Empty Constructor
     */
    SubTask() {};

    /**
    *Constructor of SubTask
    *
    *@param _name of SubTask
    *@param _type of SubTask 
    */
    SubTask(std::string _name, std::string _type);

    /**
     * Sets the values of the children vector
     */
    void setChildren(Node* _node);

    /**
     * Prints out the SubTask name and type
     */
    void print();

    /**
     * Used for debugging and testing purposes
     * Compares a pre-defined string to a pre-defined
     * json object to ensure proper conversion has occured
     * 
     * @return True if both the json object and string match, False otherwise
     */
    bool stringCompare();

    /**
     * Returns the vector of nodes that contain the children that are states
     */
    std::vector<Node*> getStateChildren();

    /**
     * Returns the vector of nodes that contain the children that are actions
     */
    std::vector<Node*> getActionChildren();

    /**
     * Deconstructor
     */
    ~SubTask() {};
};

class Action : public Node
{
private:
    std::vector<std::vector<std::string>> action;

public:

    /**
     * Constructor of Action
     *
     * @param _name of action
     * @param _type of action
     * @param _action The action conditions
     */
    Action(std::string _name, std::string _type, std::vector<std::vector<std::string>> _action);

    /**
     * Prints the conditions of the action
     */
    void printAction();

    /**
     * Prints the name, type, and conditions of
     * the action
     */
    void print();

    /**
     * Deconstructor
     */
    ~Action() {};
};

class HierarchicalTask
{

private:

    json json_obj;

    Node*   htm;

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

    /**
     * Returns the Json Object cresated by the Hierarchical Task constructor
     * @return json_obj of type json
     */
    json getJson()          { return json_obj; };

    /**
     * Returns the HTM (if any).
     *
     * @return the HTM
     */
    Node* getHTM()        { return      htm; };

    /**
     * Prints the json object
     */
    void printJson();

    /**
     * Deconstructor
     */
    ~HierarchicalTask() {};
};

/**
 * Converts the Json Object into a vector of Node pointers in a SubTask 
 * The Vector contains both Action and SubTask objects
 * @param  j Json Object
 * @return   Pointer of nodes
 */
Node* parseNode (json j);
