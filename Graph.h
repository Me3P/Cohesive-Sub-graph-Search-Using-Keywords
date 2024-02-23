#ifndef UNTITLED_GRAPH_H
#define UNTITLED_GRAPH_H


#include <list>
class Graph {
private:
    int n;
    std::list<int> *adj; // the adjacency matrix
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
