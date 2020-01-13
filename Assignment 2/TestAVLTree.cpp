#include "AvlTreeB.h"
#include <iostream> 
using namespace std;


int main(void){
    AvlTree<int> AVL;
    
    for(int i=0; i<10; i++){
        AVL.insert(i);
        AVL.printTree();
    }
    
    AVL.remove(7);
    AVL.remove(3);
    
    AVL.insert(4);
    AVL.insert(6);
    
    AVL.printTree();
    
}
