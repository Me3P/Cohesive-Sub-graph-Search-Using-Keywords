#include <vector>
#include <iostream>
#include <climits>
#include <map>
#include "Node.h"

#ifndef UNTITLED_GRAPH_H
#define UNTITLED_GRAPH_H

class Graph {
private:
    int n;
    std::map<int, std::vector<int>> adj; // the adjacency matrix
public:
    Graph();
    Graph(int);
    void addEdge(int, int);
    void deleteVertex(int);
    void deleteEdge(int, int);
    void DFS(int , int , int , int [], int [], bool []);
    void coreDecomposition();
    void findKcores(int, int[] );
    void findConnectedComponents( int , int [], int []);
    Node* KCore(Graph &, int, int []);
    };

#endif //UNTITLED_GRAPH_H
