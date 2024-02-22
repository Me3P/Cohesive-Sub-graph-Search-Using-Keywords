//
// Created by madan on 10/30/2023.
//

#include "tree.h"

void tree::inOrder(node* u) {
    if (u->children.size() !=0){
        for (auto const& v : u->children) {
            inOrder(v);
        }
    }
    if(u->vertexNumber!=-1){
        cout<<"vertex "<<u->vertexNumber<<" with core number "<<u->coreNumber<<endl;
    }
    else{
    cout<<u->id<<endl;
    }

}

tree::tree(node * root) {
    this-> root=root;
}

void tree::inOrder() {
    inOrder(root);
}
