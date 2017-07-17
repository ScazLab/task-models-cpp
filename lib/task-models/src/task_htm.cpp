#include "task-models/task_htm.h"

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
