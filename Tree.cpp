//
// Created by madan on 10/30/2023.
//

#include "Tree.h"

void Tree::inOrder(Node* u) {
    if (u->children.size() !=0){
        for (auto const& v : u->children) {
            inOrder(v);
        }
    }
    if(u->vertexNumber!=-1){
        std::cout<<"vertex "<<u->vertexNumber<<" with core number "<<u->coreNumber<<std::endl;
    }
    else{
    std::cout<<u->id<<std::endl;
    }

}

Tree::Tree(Node * root) {
    this-> root=root;
}

void Tree::inOrder() {
    inOrder(root);
}
