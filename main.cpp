#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <list>
#include "Graph.h"
#include "Node.h"
#include "Tree.h"
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>


Graph *readFile(std::string fileName){
    std::fstream file(fileName); // the text file containing the graph information
    //open a file to perform read operation using file object
    
    if (!file.is_open()){
        std::cerr << "Error opening file.\n";
        return NULL;
    }
    int from, to; // These two variables indicate the end points of an edge.   

    int numberOfVertices = 0;  // counts the number of vertices in the graph
    // ***IMP: for simplicity numberOfVertices will indicate the vertex with largest ID
    
    while(!file.eof()){
        file >> from >> to;
        numberOfVertices = std::max(numberOfVertices, std::max(from, to)+1);
    }
    
    // reset the cursor the beginning of the file.
    file.clear();
    file.seekg(0);
    
    Graph *g = new Graph(numberOfVertices);
    
    while(!file.eof()){
        file >> from >> to;
        g->addEdge(from, to);
    }
    
    file.close(); //close the file object.
    
    return g;
}

int main(int argc, char *argv[]) {
    //dd_g138 dataset 102 vertices and 518 edges
     std::string filename = argv[1];
    //  std::cout<< "datasets/" + filename << std::endl;
    Graph *g = readFile("datasets/" + filename);
    std::cout<< "Graph created \n";
    g->coreDecomposition2();

}
