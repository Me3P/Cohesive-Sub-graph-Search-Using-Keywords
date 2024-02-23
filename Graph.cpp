#include <vector>
#include<iostream>
#include <climits>
#include "Graph.h"
#include "Node.h"
#include "Tree.h"

using namespace std;
Graph::Graph(int n)
{
    this->n = n;
    adj = new list<int>[n];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
//a special DFS to find the connected k cores of a graphs, where every edge is traveresed iff both endpoints have core number
// at least k
void Graph::DFS(int u, int component, int k, int degrees[], int components[], bool visited[]){
    if(visited[u]){
        return;
    }

    visited[u]=true;
    components[u]=component;
    for(auto it= adj[u].begin(); it != adj[u].end(); ++it ){
        if (!visited[*it]&& degrees[u]>=k && degrees[*it] >=k){
            DFS(*it, component, k, degrees, components, visited);
        }
    }
}


void Graph::coreDecomposition() {
    int maxDegree=INT_MIN;
    bool* inCore=new bool[n];
    fill_n(inCore, n, false);
    int* degrees=new int[n];

    for (int i = 0; i < n; i++) {
        int temp=adj[i].size();
        degrees[i]=temp;
        if (temp>maxDegree){
            maxDegree=temp;
        }
    }

    vector<Node *> lastLevelNodes;
    vector<vector<int>> lastLevelVertices;
    int id=1;

    int* coreInformation=new int[maxDegree*(n+1)];
    int maxComponentNumber=INT_MIN;
    cout<<endl<<maxDegree<<endl;
    for(int k=1; k<=maxDegree; k++){
        cout<<k<<endl;
        vector<Node *> lastLevelNodesTemp;
        vector<vector<int>> lastLevelVerticesTemp;
        findKcores( k,  degrees);

        int * components=new int[n];
        fill_n(components, n, 0);
        findConnectedComponents(k, degrees, components);
        int maximum=INT_MIN;
        for (int i=0; i<n; i++){
           coreInformation[i + (k-1) * (n+1)]=components[i];
           if (coreInformation[i + (k-1) * (n+1)]>maximum){
               maximum=coreInformation[i + (k-1) * (n+1)];
           }
        }

        coreInformation[n + (k-1) * (n+1)]=maximum;
        if (coreInformation[n+ (k-1) * (n+1)]>maxComponentNumber){
            maxComponentNumber=coreInformation[n + (k-1) * (n+1)];
        }
    }

    Node**coreComponentInfo=new Node*[maxDegree*(maxComponentNumber+1)];
    for (int i=0; i<maxDegree*(maxComponentNumber+1); i++){
        coreComponentInfo[i]= nullptr;
    }
    static Node* root=new Node(nullptr, id,0);
    id++;
    for (int i=0; i<n;i++){
        for (int k=1; k<= maxDegree; k++){
            if(k==1){
                int componentNumber=coreInformation[i + (k-1) * (n+1)];
                if(componentNumber !=0 && coreComponentInfo [componentNumber + (k-1) * (maxComponentNumber+1)]== nullptr){
                Node* c= new Node(root, id, k);
                id++;
                coreComponentInfo[componentNumber + (k-1) * (maxComponentNumber+1)]=c;

                }
            }
            else{
                int componentNumber=coreInformation[i + (k-1) * (n+1)];
                if(componentNumber !=0 && coreComponentInfo [componentNumber + (k-1) * (maxComponentNumber+1)]== nullptr){
                    int componentLastCoreLevel=coreInformation[i + (k-2) * (n+1)];
                    Node* c= new Node(coreComponentInfo[componentLastCoreLevel + (k-2) * (maxComponentNumber+1)], id, k);
                    id++;
                    coreComponentInfo[componentNumber + (k-1) * (maxComponentNumber+1)]=c;
                }
            }
        }
    }
    
    cout << id; //TODO: what's this?

    for (int i=0; i<n; i++){
        int coreness=1;
        int k=1;
        int componentNumber= coreInformation[i + (k-1) * (n+1)];
        while(componentNumber!=0){
            coreness=k;
            k++;
            componentNumber= coreInformation[i + (k-1) * (n+1)];
        }

        cout<<"coreness of vertex "<<i<<" is "<<coreness<<endl;
        Node* NodeVertex= new Node(coreComponentInfo[coreInformation[i + (coreness-1) * (n+1)]], id, coreness, i);
        id++;
    }

    Tree decompositionTree(root);
    delete [] coreInformation;
    delete [] coreComponentInfo;
}

void Graph::findKcores(int k, int degrees[]) {
    // recursively find the vertices with degree less than k and deduct one from their degrees
    list<int> candidates;
    bool visited[n];
    bool isACandidate[n];
    fill_n(visited, n, false);
    fill_n(isACandidate, n, false);
    for (int i = 0; i < n; i++) {
        if(degrees[i]<k){
            candidates.push_back(i);
            isACandidate[i]=true;
        }
    }
    while(!candidates.empty()){
        int u=candidates.front();
        // we now remove u and all of its adjacent edges
        visited[u]=true;
        for (auto it=adj[u].begin(); it!= adj[u].end();++it){
            degrees[*it]--;
            if(degrees[*it]<k && degrees[*it]>=0 && !visited[*it]&&!isACandidate[*it]){

                candidates.push_back(*it);
                isACandidate[*it]=true;
            }
        }
        candidates.remove(u);
        isACandidate[u]=false;
    }


}

void Graph::findConnectedComponents(int k, int  degrees[], int components[]) {
    // given an integer k, find the connected k-cores of the graph and put them in the degrees [] array
    int component=1;
    fill_n(components, n, 0);
    bool* visited=new bool[n];
    fill_n(visited, n, false);
    for (int i=0; i<n; i++){
        if (!visited[i] && degrees[i]>=k){
            DFS(i,component, k, degrees, components, visited);
            component++;
        }
    }
}


