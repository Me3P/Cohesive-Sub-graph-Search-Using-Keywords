//
// Created by madan on 10/30/2023.
//

#include "node.h"
vector<node*> node::nodes;
node::node(node * parent, int id, int coreNumber) {
    this->parent= parent;
    this->id= id;
    this->coreNumber=coreNumber;
    if(parent!= nullptr){
        parent->addChild(this);
    }
    //nodes.push_back(this);
    this->vertexNumber=-1;
}
node::node(node * parent, int id, int coreNumber, int vertexNumber) {
    this->parent= parent;
    this->id= id;
    this->coreNumber=coreNumber;

    if(parent!= nullptr){
        parent->addChild(this);
    }
    nodes.push_back(this);
    this->vertexNumber=vertexNumber;
    createParentList(this);
}
void node::addChild(node * child) {
    this->children.push_back(child);
}



void node::createParentList(node *  currentNode) {
    if (currentNode==nullptr){
        return;
    }
    createParentList(currentNode->parent);
    if(currentNode!=this){
    parents.push_back(currentNode);}
}





