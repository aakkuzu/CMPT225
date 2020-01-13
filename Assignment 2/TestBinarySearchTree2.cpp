#include <stdio.h>
#include "BinarySearchTree2.h"

using namespace std;


int main(void){
    
    BinarySearchTree<int> t;
    
    
    for(int i =0; i<10; i++){
        t.insert(i);
    }
    
    int Counter = t.countInRange(0, 9);
    t.printTree();
    cout << Counter << endl;
    
    return 0;
}
