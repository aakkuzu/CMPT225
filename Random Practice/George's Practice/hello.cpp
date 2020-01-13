#include <iostream>
#include "hello.h"

using namespace std;




Hellosayer::Hellosayer(void){
    Hellosayer Hello;
    
}


void Hellosayer::getName(void){
    cout << "What is your name?\n";
    cin >> Name;
    
}


int Hellosayer::sayHello(void){
    cout << "Hello " << Name <<"\n";
    return 0; 
}
