//
// Created by madan on 10/30/2023.
//

#ifndef UNTITLED_TREE_H
#define UNTITLED_TREE_H


#include "Node.h"

class Tree {
public:
    Node * root;
    int * walkindex;
    int numNodes;
    std::vector<Node *> children;
    explicit Tree(Node *, int);
    void addChild(Node *);
    void eulerTour(Node *);
    void eulerTour();
};


#endif //UNTITLED_TREE_H
