//
// Created by madan on 10/30/2023.
//

#ifndef UNTITLED_TREE_H
#define UNTITLED_TREE_H


#include "Node.h"

class Tree {
public:
    Node* root;
    int* eulerTourSequenceIDs; /*An array of size 3n-2 containing the eulertour sequence of node ids.
                                *eulerTourSequenceIDs[i] contains the id of the i-th node in the euler tour*/
    int* eulerTourSequenceDepths; /*An array of size 3n-2 containing the eulertour sequence of node depths.
                                *eulerTourSequenceDepths[i] contains the depth of the i-th node in the euler tour*/
    int* eulerTourNodeIDS; /*An array of size n containing the eulertour sequence of node tour indexes.
                                *eulerTourNodeIDS[i] contains the tour index of the i-th index (the first time it is visited in the tour. */
    int numNodes;
    std::vector<Node*> children;
    static int eulerTourIndexCounter;
    explicit Tree(Node*, int);
    void addChild(Node*);
    void eulerTour(Node*, int);
    void eulerTour();
};


#endif //UNTITLED_TREE_H
