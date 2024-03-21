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
#include <cstdlib>

#include <sys/resource.h>


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

int setStackLimit(){
    const rlim_t kStackSize = 64 * 1024 * 1024; // 16 MB stack size limit, you can adjust this as needed

    struct rlimit rl;
    if (getrlimit(RLIMIT_STACK, &rl) == 0) {
        if (rl.rlim_cur < kStackSize) {
            rl.rlim_cur = kStackSize;
            if (setrlimit(RLIMIT_STACK, &rl) != 0) {
                std::cerr << "Failed to set stack size limit." << std::endl;
                return 1;
            }
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    int succ = setStackLimit();
    if (succ == 1) return 1;
    //dd_g138 dataset 102 vertices and 518 edges
     std::string filename = argv[1];
    //  std::cout<< "datasets/" + filename << std::endl;
    Graph *g = readFile("datasets/" + filename);
    std::cout<< "Graph created \n";
    g->coreDecomposition2();
    std::cout << "Size of the tree in data set " << filename << " is :" << Node::idCounter << '\n';
    // delete g;
    std::string command = "echo q | htop --filter=\"./output " + filename + "\" | aha --black --line-fix >  logs/" + filename + ".html";
    system(command.c_str());
    // std::cin.get();
}
