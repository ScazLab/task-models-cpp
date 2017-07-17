#include "task-models/task_htm.h"

BaseGraph::BaseGraph() {}

bool BaseGraph::equality(BaseGraph _basegraph, BaseGraph _basegraph1)
{
    return _basegraph.transitions == _basegraph1.transitions;
}

void BaseGraph::addTransition(std::string _source, std::string _label, std::string _destination)
{
    if(!transitions.count(_source))
    {
       transitions[_source];
    }
    
    std::pair<std::string, std::string> store (_label, _destination);
    List list;
    //Point point;
    //point = make_pair()
    list.insert(store);
    //hold.insert(it, store);
    transitions[_source] = list; 
}

List BaseGraph::hasTransition(std::string _source, std::string _label, std::string _destination)
{
    return transitions.at(_source);
}

// BaseGraph::all_transitions() {} //not needed for now

std::set<std::string> BaseGraph::allNodes()
{
    std::set <std::string> nodes;

    for (auto const& x : transitions)
    {   // iterate through the map; add the key (source) to nodes 
        nodes.insert(x.first);

        // then iterate through the set mapped by the key and look for 
        // each destination value in each pair and add it to node
        // x.second is the value the key is mapped to
        
        for(auto j : x.second) // I think another for-loop should be added here
        {
            nodes.insert(j.second);
        }

    }

    return nodes;
}

// this is used to pass an object to json, which then generates a string
// that is printed out; Doesn't seem to serve any other purpose
// for now, a name is not returned when this function is called
std::map<std::string, std::set<std::pair<std::string, std::string>>> BaseGraph::asDictionary(std::string _name)
{
    std::map<std::string, std::set<std::pair<std::string, std::string>>> d;
    // d["nodes"];
    // d["links"];

    List temporarylist; //change name
    std::set<std::string> nodes = allNodes();

    // moving the nodes into a set of pairs that contain the node and id # as a string
    int nodenumber = 0;

    for (auto j : nodes)
    {

        std::pair<std::string, std::string> storenodeand_id (j, std::to_string(nodenumber));
        temporarylist.insert(storenodeand_id);

        nodenumber++;
    }
    d["nodes"] = temporarylist;


    // moving the links to each of the nodes into a set of 


    // creates a dictionary with node as key, id as value
    // nodes_ids = dict([(n, i) for i, n in all_nodes])
    for (auto j : nodes)
    {

    }

    return d;
}
/*
Taskgraph::Taskgraph()
{
    //Doesn't actually do anything aside from creating the object
}

bool Taskgraph::equality(Taskgraph _taskgraph, Taskgraph _taskgraph1)
{
    if ((_taskgraph.intial == _taskgraph1.intial) && (_taskgraph.terminal == _taskgraph1.terminal))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Taskgraph::addPath()
{

}

bool Taskgraph::hasPath()
{

}

bool Taskgraph::checkOnlyDeterministicTransitionsFromState()
{

}

bool Taskgraph::checkOnlyDeterministicTransitions()
{

}

bool Taskgraph::conjugate()
{

} */

HierarchicalTask::HierarchicalTask()
{
    std::ifstream jsonFile;
    jsonFile.open("/home/andrew/Desktop/task-models-cpp/lib/task-models/src/Task_model_format.js");

    json j;
    jsonFile >> j;
    deserialization = j;

    // added for test and debugging
    namevalue = j.at("name").get<std::string>();

    children = j["children"];

    subchildren = children[0];

    action = subchildren["children"][0];

    //childrennamevalue = children.at("name").get<std::string>();

    //  childrenarray = j.at("children").get<std::unordered_map<std::string, json>>();
   //children = j.at("children").get<json::array>();
}

json HierarchicalTask::returnDeserialization()
{
    return deserialization;
}

void HierarchicalTask::printJson()
{
  //  std::cout << std::setw(4) << deserialization << std::endl;

    // added for test and debugging

    std::cout << "This is the value of name: " << namevalue << std::endl;
    

    std::cout << "This is a child of task store in array position 0 \n" << std::setw(4) << subchildren << std::endl;
    std::cout << "This is an action of a child of a child stored in position 0 \n" << std::setw(4) << action << std::endl;

    // std::cout << std::setw(4) << children << std::endl;
    //std::cout << "This is the value of name: " << childrennamevalue << std::endl;

    // std::cout << "This is the value of childrenarray: " << childrenarray << std::endl;

}

Node::Node (std::string _name, std::string _type)
{
    name = _name;
    type = _type;
}

void Node::setName(std::string _name)
{
    name = _name;
}

void Node::setType(std::string _type)
{
    type = _type;
}

void Node::printNode()
{
    std::cout << name << "\n" << std::endl;
    std::cout << type << "\n" << std::endl;
}

SubTask::SubTask(std::string _name, std::string _type) : Node(_name, _type)
{
    name = _name;
    type = _type;
}

void SubTask::printSubTask()
{
    std::cout << name << std::endl;
    std::cout << type << std::endl;
}

void SubTask::printChildren()
{
    for (std::vector<SubTask>::iterator it = children.begin(); it != children.end(); it++)
    {
        // std::cout << *it << "\n" << std::endl;
        it->printNode();
    } 

    //std::copy(begin(children), end(children), std::ostream_iterator<SubTask>(std::cout, " "));

}

Action::Action(std::string _name, std::string _type) : Node(_name, _type)
{
    name = _name;
    type = _type;
}

SubTask parseNode(json j)
{

    std::string namevalue = j.at("name").get<std::string>();
    std::string typevalue = j.at("type").get<std::string>();

    // Creates a json array-type object containing children 
    
    json childrenarray = j["children"];
    
    SubTask subtask(namevalue, typevalue);

    printf("\n");
    subtask.printSubTask();
    
    for (json::iterator it = childrenarray.begin(); it != childrenarray.end(); ++it)
    {
        json subchildrenarray = *it; 

        if (subchildrenarray.at("type").get<std::string>() == "leaf") //this should be leaf!
        {
           return subtask;
        }

        else
        {
            subtask.children.push_back(parseNode(subchildrenarray));
        }
    }

    return subtask;
}
