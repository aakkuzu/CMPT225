#include <stdio.h>
#include "BinarySearchTree1.h"

using namespace std;


int main(void){
    
    BinarySearchTree<int> BST;
    
    
    for(int i =0; i<10; i++){
        BST.insert(i);
    }
    
    int Counter = BST.sum();
    BST.printTree();
    cout << Counter << endl;
    
    return 0;
}
