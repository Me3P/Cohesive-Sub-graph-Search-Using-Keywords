//
// Created by Amirali on 10/30/2023.
//

#include "Tree.h"

void Tree::eulerTour(Node* u) {
    if (u->children.size() !=0){
        for (auto const& v : u->children) {
            eulerTour(v);
        }
    }
    if(u->vertexNumber!=-1){
        std::cout<<"vertex "<<u->vertexNumber<<" with core number "<<u->coreNumber<<std::endl;
    }
    else{
    }

}

Tree::Tree(Node * root, int n) {
    this-> root=root;
    this->numNodes=n;
}

void Tree::addChild(Node* child){
    children.push_back(child);
}

void Tree::eulerTour() {
    eulerTour(root);
}
