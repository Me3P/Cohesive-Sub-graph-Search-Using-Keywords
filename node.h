//
// Created by madan on 10/30/2023.
//
#include <iostream>
#include <vector>

using namespace std;
#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H


class node {
public:
    int id;
    int coreNumber;
    int vertexNumber;
    node* parent;
    vector<node*>parents;
    vector<node *> children;
    static vector<node *> nodes;
    node(node *, int, int);
    node(node *, int, int, int);

    void addChild(node *);
    void createParentList(node*);
};


#endif //UNTITLED_NODE_H
