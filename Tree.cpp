//
// Created by Amirali on 10/30/2023.
//

#include "Tree.h"
int Tree::eulerTourIndexCounter=0;
void Tree::eulerTour(Node* u, int depth) {
    std::cout<< u->id<<" ";
    if(eulerTourNodeIDS[u->id]==-1){
        eulerTourNodeIDS[u->id]=eulerTourIndexCounter;
    }
    eulerTourSequenceIDs[eulerTourIndexCounter]=u->id;
    eulerTourSequenceDepths[eulerTourIndexCounter]=depth;
    eulerTourIndexCounter++;
    if (u->children.size() !=0){
        for (auto const& v : u->children) {
            eulerTour(v, depth+1);
            std::cout<<u->id<<" ";
            eulerTourSequenceIDs[eulerTourIndexCounter]=u->id;
            eulerTourSequenceDepths[eulerTourIndexCounter]=depth;
            eulerTourIndexCounter++;
        }
    }
}

Tree::Tree(Node * root, int n) {
    this-> root=root;
    this->numNodes=n;
    eulerTourSequenceIDs=new int[3*numNodes-2];
    eulerTourSequenceDepths=new int[3*numNodes-2];
    eulerTourNodeIDS=new int[numNodes];
    std::fill_n(eulerTourNodeIDS, numNodes, -1);
}

void Tree::addChild(Node* child){
    children.push_back(child);
}

void Tree::eulerTour() {
    eulerTour(root,0);
}
