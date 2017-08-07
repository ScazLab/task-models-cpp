#include "task-models/task_htm.h"

HierarchicalTask::HierarchicalTask()
{

}

HierarchicalTask::HierarchicalTask(std::string _filename)
{
    std::ifstream jsonFile;
    jsonFile.open(_filename);

    jsonFile >> json_obj;

    htm = parseNode(json_obj);
}

void HierarchicalTask::printJson()
{
    //  std::cout << std::setw(4) << json_obj << std::endl;
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

void Node::print()
{
    std::cout << "Node name: " << name << "\ttype: " << type << std::endl;
}

SubTask::SubTask(std::string _name, std::string _type) : Node(_name, _type)
{
    name = _name;
    type = _type;
}

void SubTask::setChildren(Node* _node)
{
    children.push_back(_node);
}

void SubTask::printChildren()
{
    for (std::vector<Node*>::iterator it = children.begin(); it != children.end(); it++)
    {   
        (*it)->print();
    }
}

void SubTask::print()
{
    Node::print();
    printChildren();
    printf("\n");
}

bool SubTask::stringCompare()
{
    //define the method
    print();
    
    return false;
}

std::vector<Node*> SubTask::getStateChildren()
{
    std::vector<Node*> statevector;

    for (std::vector<Node*>::iterator it = children.begin(); it != children.end(); it++)
    {   
        Node* compare = *it;

        if (compare->getType() == "sequential")
        {
            statevector.push_back(*it);
        }  
    }

    return statevector;
}

std::vector<Node*> SubTask::getActionChildren()
{
    //define this later to return the type of
    //vector that "supportivepomdp" expects 
    std::vector<Node*> actionvector;

    return actionvector;
}

Action::Action(std::string _name, std::string _type, std::vector<std::vector<std::string>> _action) : Node(_name, _type)
{
    name = _name;
    type = _type;
    action = _action;
}

void Action::printAction()
{
   for (std::vector<std::vector<std::string>>::iterator it = action.begin(); it != action.end(); it++)
   {
        std::vector<std::string> temp = *it;
        for (std::vector<std::string>::iterator itt = temp.begin(); itt != temp.end(); itt++)
        {
            std::cout << *itt << std::endl;
        }
   }
}

void Action::print()
{
    Node::print();
    printAction();
    printf("\n");
}

Node* parseNode(json j)
{
    std::string namevalue = j.at("name").get<std::string>();
    std::string typevalue = j.at("type").get<std::string>();
    json childrenarray = j["children"];

    SubTask* subtask = new SubTask(namevalue, typevalue);
    printf("\n");

    for (json::iterator it = childrenarray.begin(); it != childrenarray.end(); ++it)
    {
        json subchildrenarray = *it;

       if (subchildrenarray.at("type").get<std::string>() == "leaf") 
        {
            namevalue = subchildrenarray.at("name").get<std::string>();
            typevalue = subchildrenarray.at("type").get<std::string>();

            json conditionarray = subchildrenarray["action"]["conditions"];
            std::vector<std::vector<std::string>> actionvalue;

            for (unsigned int i = 0; i < conditionarray.size(); i++)
            {
                std::vector<std::string> subvalue;
                
                for (unsigned int j = 0; j < 2; j++)
                {
                    subvalue.push_back(conditionarray[i][j]);
                } 
                
                actionvalue.push_back(subvalue);
            }

           // subtask->children.push_back(new Action(namevalue, typevalue, actionvalue));
              subtask->setChildren(new Action(namevalue, typevalue, actionvalue));
        }
       
        else
        {
          //  subtask->children.push_back(parseNode(subchildrenarray));
              subtask->setChildren(parseNode(subchildrenarray));
        }
    }

    Node* res = subtask;
    return res;
}
