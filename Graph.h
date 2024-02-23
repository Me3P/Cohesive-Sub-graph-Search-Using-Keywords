#include <vector>
#include <iostream>
#include <climits>

#ifndef UNTITLED_GRAPH_H
#define UNTITLED_GRAPH_H

class Graph {
private:
    int n;
    std::vector<std::vector<int>> adj; // the adjacency matrix
public:
    Graph();
    Graph(int n);
    void addEdge(int u, int v);
    void DFS(int , int , int k, int [], int [], bool []);
    void coreDecomposition();
    void findKcores(int, int[] );
    void findConnectedComponents( int , int [], int []);

    };



#endif //UNTITLED_GRAPH_H
