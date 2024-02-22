#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include "Graph.h"
#include "node.h"
#include "tree.h"
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
int add(int a1, int a2){
    return a1+a2;
}

void chap (int nums []){
    for (int i=0; i<= 8; i++){
        nums[i]++;
    }

}
void chap(vector<int> & numbers){
    for (int i=0; i<4; i++){
        cout<<numbers[i];
    }
}



void chap(list<int>* alefba){
    cout<<alefba[0].front();
}
int main() {

    int a = 10;

   int numbers[10] = {1, 2, 3, 4};
    Graph g1(13);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(1, 5);
    g1.addEdge(2, 3);
    g1.addEdge(2, 4);
    g1.addEdge(2, 5);
    g1.addEdge(2, 6);
    g1.addEdge(3, 4);
    g1.addEdge(3, 6);
    g1.addEdge(3, 7);
    g1.addEdge(4, 6);
    g1.addEdge(4, 7);
    g1.addEdge(5, 6);
    g1.addEdge(5, 8);
    g1.addEdge(6, 7);
    g1.addEdge(6, 8);
    g1.addEdge(9, 10);
    g1.addEdge(11, 12);
    //g1.coreDecomposition();


    //vector<bool> visited(10, false);
    //g1.DFS2(0, visited);
    //g1.printDegrees();
    //vector<int> salam(9, 0);
    /*int * kir= new int[10];
    fill_n(kir, 10, 0);
    for (int i=0; i<10; i++){
        cout<< kir[i];
    }
    list<int> * kiri;
    kiri=new list<int>[10];
    for (int i=0; i<10; i++){
        kiri[i].push_back(i);
        kiri[i].push_back(i+1);
    }
    for (int i=0; i<10; i++){
        for (auto it=kiri[i].begin(); it!= kiri[i].end(); ++it){
            cout<<*it;
        }
        cout<<endl;
    }*/

    /*list<int> *alefba = new list<int>;
    alefba[0].push_back(1);
    g1.coreDecomposition();
    vector<int *> chetori;
    int r = 10;
    chetori.push_back(&r);
    //cout<<*chetori.front();
    node root(nullptr, 1, 0);
    node c2(&root, 2, 0);
    node c3(&root, 3, 0);
    node c4(&c2, 4, 0);
    node c5(&c2, 5, 0);
    node c6(&c3, 6, 0);
    node c7(&c3, 7, 0);
    //node c4(&);
    //tree t1(&root);
    //t1.inOrder();
    vector<node *> lastLevelnodes;
    vector<vector<int>> lastLevelVertices;
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    vector<int> v2;
    v2.push_back(4);
    v2.push_back(5);
    v2.push_back(6);
    lastLevelVertices.push_back(v1);
    lastLevelVertices.push_back(v2);
    lastLevelnodes.push_back(&root);
    lastLevelnodes.push_back(&c2);
    int i = 0;*/


    /* for (auto const& v : lastLevelnodes) {
         cout<< v->id<<":"<<endl;
         for (auto it= lastLevelVertices[i].begin(); it!=lastLevelVertices[i].end(); ++it){
         cout<<*it<<" ";
         }
         cout<<endl;
         i++;
     }*/

    fstream newfile;
    string fileName = "C:\\Users\\madan\\Desktop\\datasets\\144.txt";
    newfile.open(fileName, ios::in); //open a file to perform read operation using file object
    int maxVertexNumberDataset=INT_MIN;
    int edgeNumberDataset=0;
    if (newfile.is_open()) { //checking whether the file is open
        string tp;
        while (getline(newfile, tp)) { //read data from file object and put it into string.
            string s;
            stringstream ss(tp);
            while (getline(ss, s, ' ')) {
                int currentVertex=stoi(s);
                if(currentVertex > maxVertexNumberDataset){
                    maxVertexNumberDataset=currentVertex;
                }
            }
            edgeNumberDataset++;
        }
        newfile.close(); //close the file object.
    }
    //dd_g138 dataset 102 vertices and 518 edges
    int numberOfVertices=102;
    int numberOfEdges=518;
   /* if(numberOfVertices!= maxVertexNumberDataset){
        //cout<<"The provided number of vertices does not match the dataset.";
    }

    else if(numberOfEdges!=edgeNumberDataset){
       // cout<<"The provided number of edges does not match the dataset.";
    }*/
cout<<"The dataset has "<<maxVertexNumberDataset<<" vertices and "<<edgeNumberDataset<<" edges."<<endl;
        newfile.open(fileName, ios::in); //open a file to perform read operation using file object

        Graph g2(maxVertexNumberDataset);
        cout<<maxVertexNumberDataset;
        if (newfile.is_open()) { //checking whether the file is open
            string tp;
            while (getline(newfile, tp)) { //read data from file object and put it into string.
                string s;
                stringstream ss(tp);
                int vertices[2];
                int j = 0;
                while (getline(ss, s, ' ')) {
                    int currentVertex = stoi(s);
                    if (currentVertex > numberOfVertices) {
                        numberOfVertices = currentVertex;
                    }
                    vertices[j] = currentVertex;
                    j++;
                }
                numberOfEdges++;
                g2.addEdge(vertices[0] - 1, vertices[1] - 1);
                //cout << vertices[0] << "\n" << vertices[1] << "\n";
                //cout << tp << "\n"; //print the data of the string
            }
            newfile.close(); //close the file object.
        }
        cout<<"here";
       g2.coreDecomposition();
       int numbers2[10];
       cout<<numbers[11];

        int rows=2;
        int columns=3;
        int test[rows][columns];
        int test2[rows*columns];
        int counter=0;
        for (int i=0; i<rows *columns; i++){
            test2[i]=counter;
            counter++;
        }
        int i=1;
        int j=1;
        cout<<endl<<test2[j + i * columns];
   }
