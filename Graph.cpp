#include "Graph.h"
#include "Node.h"
#include "Tree.h"
#include <vector>
#include <iostream>
#include <climits>
#include <list>
#include <queue>
#include<algorithm>

Graph::Graph(int n)
{
    this->n = n;
    for (int i = 0; i < n; i++){
        std::vector<int> v;
        this->adj[i] = v;
    }
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
//a special DFS to find the connected k cores of a graphs, where every edge is traveresed iff both endpoints have core number
// at least k
void Graph::DFS(int u, int component, int k, int degrees[], int components[], bool visited[]){
    if(visited[u]) 
        return;
        
    visited[u]=true;
    components[u]=component;
    for(auto it = adj[u].begin(); it != adj[u].end(); ++it){
        int node = *it;
        if (!visited[node] && degrees[u] >= k && degrees[node] >= k){
            DFS(node, component, k, degrees, components, visited);
        }
    }
}


void Graph::coreDecomposition() {
    int maxDegree = 0;
    bool* inCore = new bool[n];
    std::fill_n(inCore, n, false);
    int* degrees = new int[n];

    for (int i = 0; i < n; i++) {
        degrees[i]=adj[i].size();
        maxDegree = std::max(maxDegree, degrees[i]);
    }

    std::vector<Node*> lastLevelNodes;
    std::vector<std::vector<int>> lastLevelVertices;
    int id=1;

    int** coreInformation = new int*[maxDegree];
    for(int i = 0; i < maxDegree; ++i)
        coreInformation[i] = new int[n+1];
    
    // int* coreInformation=new int[maxDegree* (n+1)];
    int maxComponentNumber=0;
    // std::cout<<std::endl<<maxDegree<<std::endl;
    for(int k=1; k<=maxDegree; k++){
        // std::cout<<k<<std::endl;
        std::vector<Node *> lastLevelNodesTemp;
        std::vector<std::vector<int>> lastLevelVerticesTemp;
        findKcores(k,  degrees);

        int* components = new int[n];
        std::fill_n(components, n, 0);
        findConnectedComponents(k, degrees, components);
        int maximum = 0;
        for (int i = 0; i < n; i++){
           coreInformation[k-1][i]=components[i];
           maximum=std::max(maximum, coreInformation[k-1][i]);
        }

        coreInformation[k-1][n]=maximum;
        maxComponentNumber=std::max(maxComponentNumber, coreInformation[k-1][n]);
    }

    Node** coreComponentInfo = new Node*[maxDegree*(maxComponentNumber+1)];
    for (int i=0; i<maxDegree*(maxComponentNumber+1); i++){
        coreComponentInfo[i]= nullptr;
    }
    static Node* root = new Node(nullptr, id,0);
    id++;
    for (int i = 0; i < n; i++){
        for (int k = 1; k <= maxDegree; k++){
            if(k == 1){
                int componentNumber=coreInformation[k-1][i];
                if(componentNumber !=0 && coreComponentInfo [componentNumber + (k-1) * (maxComponentNumber+1)]== nullptr){
                Node* c= new Node(root, id, k);
                id++;
                coreComponentInfo[componentNumber + (k-1) * (maxComponentNumber+1)]=c;

                }
            }
            else{
                int componentNumber=coreInformation[k-1][i];
                if(componentNumber !=0 && coreComponentInfo [componentNumber + (k-1) * (maxComponentNumber+1)]== nullptr){
                    int componentLastCoreLevel=coreInformation[k-2][i];
                    Node* c= new Node(coreComponentInfo[componentLastCoreLevel + (k-2) * (maxComponentNumber+1)], id, k);
                    id++;
                    coreComponentInfo[componentNumber + (k-1) * (maxComponentNumber+1)]=c;
                }
            }
        }
    }

    for (int i = 0; i < n; i++){
        int coreness = 1;
        int k = 1;
        int componentNumber= coreInformation[k-1][i];
        while(componentNumber!=0){
            coreness=k;
            k++;
            componentNumber = coreInformation[k-1][i];
        }

        // std::cout<<"coreness of vertex "<<i<<" is "<<coreness<<std::endl;
        Node* NodeVertex= new Node(coreComponentInfo[coreInformation[coreness-1][i]], coreness, i);
    }

    Tree decompositionTree(root, Node::idCounter);
    delete [] coreInformation;
    delete [] coreComponentInfo;
}

void Graph::findKcores(int k, int degrees[]) { //TODO: change degrees to a map or hashmap and only work with remaning vertices.
    // recursively find the vertices with degree less than k and deduct one from their degrees
    std::queue<int> candidates;
    bool *visited = new bool[n];
    // bool *isACandidate = new bool[n];
    std::fill_n(visited, n, false);
    // std::fill_n(isACandidate, n, false);
    for (int i = 0; i < n; i++){
        if(degrees[i]<k){
            candidates.push(i);
            // isACandidate[i]=true;
        }
    }
    while(!candidates.empty()){
        int u=candidates.front();
        // we now remove u and all of its adjacent edges
        visited[u]=true;
        for (auto it=adj[u].begin(); it!= adj[u].end();++it){
            degrees[*it]--;
            // if(degrees[*it] < k && degrees[*it] >= 0 && !visited[*it] && !isACandidate[*it]){
            //     candidates.push_back(*it);
            //     isACandidate[*it]=true;
            // }
            
            if(degrees[*it] = k - 1){
                candidates.push(*it);
                // isACandidate[*it]=true;
            }
        }
        candidates.pop();
        // isACandidate[u]=false;
    }
}

void Graph::findConnectedComponents(int k, int  degrees[], int components[]) {
    // given an integer k, find the connected k-cores of the graph and put them in the degrees [] array
    int component=1;
    std::fill_n(components, n, 0);
    bool* visited=new bool[n];
    std::fill_n(visited, n, false);
    for (int i=0; i<n; i++){ // TODO: change n to remaining vertices
        if (!visited[i] && degrees[i]>=k){
            DFS(i,component, k, degrees, components, visited);
            component++;
        }
    }
}

Node* Graph::KCore(Graph &g, int k, int degrees[]){
    // recursively find the vertices with degree less than k and deduct one from their degrees
    std::queue<int> candidates;
    // bool *visited = new bool[n];
    // std::fill_n(visited, n, false);
    n = adj.size();
    for (int i = 0; i < n; i++){
        if(degrees[i] < k){
            candidates.push(i);
        }
    }
    while(!candidates.empty()){
        int u = candidates.front();
        candidates.pop();
        // we now remove u and all of its adjacent edges
        for (auto it = adj[u].begin(); it != adj[u].end();++it){
            degrees[*it]--;
            deleteEdge(*it, u);
            if(degrees[*it] = k - 1){
                candidates.push(*it);
            }
        }
        g.deleteVertex(u);
    }
    Node* root = new Node(nullptr, k);
    bool* visited=new bool[n];
    std::fill_n(visited, n, false);
    for (int i=0; i<n; i++){ // TODO: change n to remaining vertices
        if (!visited[i] && degrees[i]>=k){
            KCore(g, k, degrees);
        }
    }
    k++;
return root;
}

void Graph::deleteVertex(int u){
    adj.erase(u);
}

void Graph::deleteEdge(int u, int v){ // TODO fix  this function
    // std::vector<int> &vec = adj.find(u)->second;
    // vec.erase(std::find(vec.begin(), vec.end(), v));
}
Tree* Graph::coreDecomposition2() {
    int numRemainingVertices = n; // to denote how many vertices are left
    Node** nodeContainingVertex = new Node* [n]; // to track the nodes of the last level of the
    //decomposition tree
    Node* root = new Node(nullptr, 0);
    int coreValue = 1;
    std::fill_n(nodeContainingVertex, n, root);
    // nodeContainingVertex[i] stores the pointer to the lowest tree node containing node i so far
    while(numRemainingVertices > 0){
        std::cout<< " Coreness " << coreValue << " in progress .... \n";
        int numVerticesRemoved = findKcores(coreValue, nodeContainingVertex);
        numRemainingVertices -= numVerticesRemoved; //TODO check for memory leak
        findConnectedComponents(coreValue, nodeContainingVertex);//TODO check here
        coreValue++;
    }
    Tree* decompositionTree = new Tree(root, Node::idCounter); // TODO build the pointer to parent (baseline)

    return decompositionTree;
}
//TODO Update this method to accept a graph object as input, so that we can copy the original graph
int Graph::findKcores(int k, Node** nodeContainingVertex) { //return is the number of removed vertices
    // recursively find the vertices with degree less than k and deduct one from their degrees
    int numVerticesRemoved=0;
    std::queue<int> candidates;
    // bool *visited = new bool[n];
    // std::fill_n(visited, n, false);
    // std::fill_n(isACandidate, n, false);
   for(auto it = adj.begin(); it != adj.end(); ++it){
       if (it->second.size() < k){ // == k-1
           candidates.push(it->first);
       }
    }
    while(!candidates.empty()){
        int u=candidates.front();
        // we now remove u and all of its adjacent edges
        // visited[u]=true;
        for (auto it=adj[u].begin(); it!= adj[u].end();++it){
            adj[*it].erase(std::remove(adj[*it].begin(), adj[*it].end(), u), adj[*it].end()); // remove u from all adjacency lists of
            //its neighbours
            if(adj[*it].size() == k - 1){
                candidates.push(*it);
            }
        }
        candidates.pop();
         std::cout<< u << " Coreness: " << k-1 << '\n';//TODO is coreness k or k-1?
        //since we are about to erase u, we make u's node in the decomposition tree
        Node* nodeVertex = new Node(nodeContainingVertex[u],  k-1, u);
        nodeContainingVertex[u]=nodeVertex;
        nodeVertex->createParentList();
        adj.erase(u);
        numVerticesRemoved++;
    }
    return numVerticesRemoved;
}

void Graph::findConnectedComponents(int k, Node** nodeContainingVertex) {
    // given an integer k, find the connected k-cores of the graph and put them in the degrees [] array
    int component = 1;
    bool* visited = new bool[n];
    std::fill_n(visited, n, false);
    for (auto it = adj.begin(); it != adj.end(); ++it){ // TODO: change n to remaining vertices
        int u = it->first;
        if (!visited[u]){
            // we are starting a new component, so we create its tree node
            Node* componentNode = new Node(nodeContainingVertex[u], k);
            componentNode->createParentList();
            DFS(u, k, nodeContainingVertex, componentNode, visited);
            component++;
        }
    }
}

void Graph::DFS(int u, int k, Node** nodeContainingVertex, Node* componentNode, bool visited[]){
    if(visited[u])
        return;

    visited[u] = true;
    nodeContainingVertex[u] = componentNode;
    for(auto it = adj[u].begin(); it != adj[u].end(); ++it){
        int node = *it;
        if (!visited[node]){
            DFS(node, k,  nodeContainingVertex, componentNode,  visited);
        }
    }
}


