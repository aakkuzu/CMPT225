#include <stdio.h>
#include "List.h"
#include "Vector.h"
#include <iostream>




using namespace std;


template<typename T>

void print(const T& obj){
    
    for (auto item: obj){
        cout << item <<endl;
    }
}


int main(void){
    const int n = 10;
    List<int> L1;
    Vector<int> V1;
  
  
    ///LIST TEST///
    L1.push_back(7);
  
    for(int i=0; i<n; i++){
        L1.push_back(i);
        L1.push_back(7);
    }
   
    L1.push_back(7);
    L1.push_back(7);
    
    cout << "done pushing\n"<< endl;

    
    L1.replaceAll(7,8);
    L1.removeAll(8);
    
    print(L1);
    
    
    ///VECTOR TEST///
    V1.push_back(7);
  
    for(int i=0; i<n; i++){
        V1.push_back(i);
        V1.push_back(7);
    }
   
    V1.push_back(7);
    V1.push_back(7);
    
    cout << "done pushing\n"<< endl;

    
    V1.replaceAll(7,8);
    V1.removeAll(8);
    
    print(V1);

    
}
