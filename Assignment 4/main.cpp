#include <iostream>
#include <fstream>

using namespace std;



int letterFrequencies[257];

void initializeLetterFrequencies()
{
    for(int i=0; i<=256; i++){
        letterFrequencies[i] = 0;
    }
    
}

void frequencyCounter(char character)
{
    
    for (int i=0; i<=256; i++)
    {
        if(i == (int) character){
            letterFrequencies[i]++;
        }
        
    }
}

template<typename T>
void printArray(T* arr, int lenght){
    
    cout<<"Array: ["<<endl;
    for(int i=0; i<lenght; i++){
        if(arr[i] >0){
            cout<<"\t"<<i<<"\t=> "<<arr[i]<<","<<endl;
    
            
        }
    }
    cout<<"]"<<endl;
    
}




int main(int argc,char* argv[])
{
    initializeLetterFrequencies();
    
    if(argc < 2)
    {
        cerr<<"Please specify a file"<<endl;
        return 1;
    }
    
    
    char myChar;
    
    ifstream inputFile(argv[1]);
    
    //inputFile>>myChar;
        
    while(inputFile.get(myChar))
    {
        frequencyCounter(myChar);
    }
        
        
    printArray(letterFrequencies,256);
    
    
    
}
