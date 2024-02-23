#include "Node.h"
std::vector<Node*> Node::Nodes;
Node::Node(Node * parent, int id, int coreNumber) {
    this->parent= parent;
    this->id= id;
    this->coreNumber=coreNumber;
    if(parent!= nullptr){
        parent->addChild(this);
    }
    this->vertexNumber=-1;
}

Node::Node(Node * parent, int id, int coreNumber, int vertexNumber) {
    this->parent= parent;
    this->id= id;
    this->coreNumber=coreNumber;
    if(parent!= nullptr){
        parent->addChild(this);
    }
    Nodes.push_back(this);
    this->vertexNumber=vertexNumber;
    createParentList(this);
}

void Node::addChild(Node * child) {
    this->children.push_back(child);
}

void Node::createParentList(Node *  currentNode) {
    if (currentNode==nullptr){
        return;
    }
    createParentList(currentNode->parent);
    if(currentNode!=this){
    parents.push_back(currentNode);}
}





