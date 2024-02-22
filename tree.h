//
// Created by madan on 10/30/2023.
//

#ifndef UNTITLED_TREE_H
#define UNTITLED_TREE_H


#include "node.h"

class tree {
public:
    node * root;
    explicit tree(node *);
    void inOrder(node *);
    void inOrder();
};


#endif //UNTITLED_TREE_H
