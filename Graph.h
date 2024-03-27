#include <vector>
#include <iostream>
#include <climits>
#include <map>
#include "Node.h"
#include "Tree.h"

#ifndef UNTITLED_GRAPH_H
#define UNTITLED_GRAPH_H

class Graph {
private:
    int n;
    std::map<int, std::vector<int>> adj; // the adjacency matrix
public:
    static long long int totalCores;
    Graph();
    Graph(int);
    ~Graph();
    void addEdge(int, int);
    void deleteVertex(int);
    void deleteEdge(int, int);
    void DFS(int , int , int , int [], int [], bool []);
    void coreDecomposition();
    void findKcores(int, int[] );
    void findConnectedComponents(int , int [], int []);
    int findKcores(int, Node**);
    Node* KCore(Graph &, int, int []);
    Tree* coreDecomposition2();
    void findConnectedComponents(int k, Node** nodeContainingVertex);
    void DFS(int u, int k, Node** nodeContainingVertex, Node* componentNode, bool visited[]);
    void findConnectedComponentsHeapRecursion(int k, Node** nodeContainingVertex);
};


#endif //UNTITLED_GRAPH_H
