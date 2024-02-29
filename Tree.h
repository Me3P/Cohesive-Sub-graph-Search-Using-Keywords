//
// Created by madan on 10/30/2023.
//

#ifndef UNTITLED_TREE_H
#define UNTITLED_TREE_H


#include "Node.h"

class Tree {
public:
    Node * root;
    std::vector<Node *> children;
    explicit Tree(Node *);
    void addChild(Node *);
    void inOrder(Node *);
    void inOrder();
};


#endif //UNTITLED_TREE_H
