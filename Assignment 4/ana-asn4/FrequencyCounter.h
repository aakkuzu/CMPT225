#pragma once

#include <fstream>
#include <iostream>

const int NUMBER_OF_CHARS = 256;

using namespace std;




class FrequencyCounter
{
public:
    
    FrequencyCounter()
    {
        reset();
    }
    
    
    void reset()
    {
        for(int i=0; i<NUMBER_OF_CHARS; i++){
            letterFrequencies[i] = 0;
        }
    }
    
    
    void countFile(char* filename)
    {
        
        char myChar;
        
        ifstream inputFile(filename);
            
        while(inputFile.get(myChar))
        {
            increment(myChar);
        }
        
    }
    
    int getCount(char c)
    {
        
        return letterFrequencies[(int)((unsigned char)c)];
    }
    
    
    
    void debugPrint()
    {
        cout<<"Non Zero frequencies: ["<<endl;
        for(int i=0; i<NUMBER_OF_CHARS; i++){
            if(letterFrequencies[i]>0){
                cout<<"\t"<<i<<"\t=> "<<letterFrequencies[i]<<","<<endl;
            }
        }
          cout<<"]"<<endl;
        
    }
    
        

    

private:
    
    void increment(char character)
    {
        
     letterFrequencies[(unsigned int)character]++;
       
    }
    
    int letterFrequencies[NUMBER_OF_CHARS];
};
