//
// Created by amirali on 10/30/2023.
//
#include <iostream>
#include <vector>

#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H


class Node {
public:
    static int id;
    int coreNumber;
    int vertexNumber;
    Node* parent;
    std::vector<Node*>parents;
    std::vector<Node *> children;
    static std::vector<Node *> Nodes;
    Node(Node *, int);
    Node(Node *, int, int);

    void addChild(Node *);
    void createParentList(Node*);
};


#endif //UNTITLED_NODE_H
