#include <stdio.h>
#include <iostream>
#include "List.h"
#include "Vector.h"
#include <time.h>
#include <cstdlib>


using namespace std;



void identification(){
    std::string name = "Anastasia Akkuzu";
    std::string studentNumber = "301316633";
    std::string loginId = "aakkuzu";
    
    
    
    cout<< name <<endl;
    cout<< studentNumber <<endl;
    cout<< loginId <<endl;
}

void doubleType(int x, int y){
    cout<< "Type of Elements: Double" <<endl;
    cout<< "Number of Elements Added: "<< y <<endl;
    cout<< "Number of Elements Changed/Removed: " << x <<endl;
    cout<< "Time units: Milliseconds" <<endl;
}

void intType(int x, int y){
    cout<< "Type of Elements: Integers" <<endl;
    cout<< "Number of Elements Added: " << y <<endl;
    cout<< "Number of Elements Changed/Removed: " << x <<endl;
    cout<< "Time units: Milliseconds" <<endl;
}

double elapsedTime(clock_t start,clock_t finish){
    return (finish - start)/(double)( CLOCKS_PER_SEC / 1000 );
}

int n = 100000;

//// INT TESTING ////


double vInsertInt(){
    
    
    Vector<int> V1;
    int randomNumber;
    
    clock_t start = clock();
    for(int i=0; i<= n; i++){
        randomNumber = rand() % 10;
        V1.push_back(randomNumber);
    }
    clock_t finish = clock();
    
    return elapsedTime(start, finish);
}

double vSwapInt(){
    
    
    Vector<int> V1;
    int randomNumber;
    
    
    for(int i=0; i<= n; i++){
        randomNumber = rand() % 10;
        V1.push_back(randomNumber);
    }
    clock_t start = clock();
    V1.replaceAll(3,5);
    clock_t finish = clock();
    
    return elapsedTime(start, finish);
}

double vDeleteInt(int deleteMe){
    
    
    Vector<int> V1;
    int randomNumber;
    
    
    for(int i=0; i<= n; i++){
        randomNumber = rand() % 10;
        V1.push_back(randomNumber);
    }
    clock_t start = clock();
    V1.removeAll(deleteMe);
    clock_t finish = clock();
    
    return elapsedTime(start, finish);
}


double lInsertInt(){
    
    
    List<int> L1;
    int randomNumber;
    
    clock_t start = clock();
    for(int i=0; i<= n; i++){
        randomNumber = rand() % 10;
        L1.push_back(randomNumber);
    }
    clock_t finish = clock();
    
    return elapsedTime(start, finish);
}

double lSwapInt(){
    
    
    List<int> L1;
    int randomNumber;
    
    
    for(int i=0; i<= n; i++){
        randomNumber = rand() % 10;
        L1.push_back(randomNumber);
    }
    clock_t start = clock();
    L1.replaceAll(3,5);
    clock_t finish = clock();
    
    return elapsedTime(start, finish);
}

double lDeleteInt(int deleteMe){
    
    
    List<int> L1;
    int randomNumber;
    
    
    for(int i=0; i<= n; i++){
        randomNumber = rand() % 10;
        L1.push_back(randomNumber);
    }
    clock_t start = clock();
    L1.removeAll(deleteMe);
    clock_t finish = clock();
    
    return elapsedTime(start, finish);
}







//// DOUBLE TESTING ////
double vInsertDouble(){
    
    
    Vector<int> V1;
    double randomNumber;
    
    clock_t start = clock();
    for(int i=0; i<= n; i++){
        randomNumber = rand() % 10;
        V1.push_back(randomNumber);
    }
    clock_t finish = clock();
    
    return elapsedTime(start, finish);
}

double vSwapDouble(){
    
    
    Vector<int> V1;
    double randomNumber;
    
    
    for(int i=0; i<= n; i++){
        randomNumber = rand() % 10;
        V1.push_back(randomNumber);
    }
    clock_t start = clock();
    V1.replaceAll(3,5);
    clock_t finish = clock();
    
    return elapsedTime(start, finish);
}

double vDeleteDouble(double deleteMe){
    
    
    Vector<int> V1;
    double randomNumber;
    
    
    for(int i=0; i<= n; i++){
        randomNumber = rand() % 10;
        V1.push_back(randomNumber);
    }
    clock_t start = clock();
    V1.removeAll(deleteMe);
    clock_t finish = clock();
    
    return elapsedTime(start, finish);
}


double lInsertDouble(){
    
    
    Vector<int> L1;
    double randomNumber;
    
    clock_t start = clock();
    for(int i=0; i<= n; i++){
        randomNumber = rand() % 10;
        L1.push_back(randomNumber);
    }
    clock_t finish = clock();
    
    return elapsedTime(start, finish);
}

double lSwapDouble(){
    
    
    Vector<int> L1;
    double randomNumber;
    
    
    for(int i=0; i<= n; i++){
        randomNumber = rand() % 10;
        L1.push_back(randomNumber);
    }
    clock_t start = clock();
    L1.replaceAll(3,5);
    clock_t finish = clock();
    
    return elapsedTime(start, finish);
}

double lDeleteDouble(double deleteMe){
    
    
    Vector<int> L1;
    double randomNumber;
    
    
    for(int i=0; i<= n; i++){
        randomNumber = rand() % 10;
        L1.push_back(randomNumber);
    }
    clock_t start = clock();
    L1.removeAll(deleteMe);
    clock_t finish = clock();
    
    return elapsedTime(start, finish);
}






int main(void){
    
   
    /////Int Sector/////
    
    /*
     Class info   
     */
    identification();
   
    /*
     Types of items
     */
    intType(n, n);
    
    /*
     Clocked times
     */
    cout << "Time for Vector Insertion: " << vInsertInt() << endl;
    cout << "Time for List Insertion: " << lInsertInt() << endl;
    cout << "Time for Vector Change: " << vSwapInt() << endl;
    cout << "Time for List Change: " << lSwapInt() << endl;
    cout << "Time for Vector Deletion: " << vDeleteInt(35) << endl;
    cout << "Time for List Deletion: " << lDeleteInt(35) << endl;
    
    
    
    
    /////Double Sector/////
    
    /*Clocked times
     
    
    cout << "Time for Vector Insertion: " << vInsertDouble() << endl;
    cout << "Time for List Insertion: " << lInsertDouble() << endl;
    cout << "Time for Vector Change: " << vSwapDouble() << endl;
    cout << "Time for List Change: " << lSwapDouble() << endl;
    cout << "Time for Vector Deletion: " << vDeleteDouble(35) << endl;
    cout << "Time for List Deletion: " << lDeleteDouble(35) << endl;
    */
    
    return 0;
    
    
    
    
}
