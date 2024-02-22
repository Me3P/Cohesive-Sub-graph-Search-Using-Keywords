//
// Created by madan on 10/14/2023.
//

#ifndef UNTITLED_GRAPH_H
#define UNTITLED_GRAPH_H


//
// Created by madan on 10/14/2023.
//

#ifndef UNTITLED_KIR_H
#define UNTITLED_KIR_H


//
// Created by madan on 10/13/2023.
//

#include <list>
using namespace std;
class Graph {
private:
    int n;
    list<int> *adj; // the adjacency matrix
public:
    Graph(int n);
    void addEdge(int u, int v);
    void DFS(int , int , int k, int [], int [], bool []);
    void coreDecomposition();
    void findKcores(int, int[] );
    void findConnectedComponents( int , int [], int []);

    };



#endif //UNTITLED_KIR_H

#endif //UNTITLED_GRAPH_H
