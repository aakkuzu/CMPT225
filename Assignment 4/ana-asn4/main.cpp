#include <iostream>
#include <cstring>
#include <fstream>

#include "FrequencyCounter.h"
#include "HuffmanTree.h"

#include "BitStream.h"

using namespace std;








void compress(char* filename)
{
    FrequencyCounter fc;
    fc.countFile(filename);
       
    HuffmanTree t(fc);

    
    
    ifstream inps(filename);
    
    
    char* new_name = new char[strlen(filename)+5];
    strcpy(new_name,filename);
    strcat(new_name,".huff");
    
    OutputBitStream ops(new_name);
    
    
    t.encode(inps,ops);
    
}




int main(int argc,char* argv[])
{
    bool debug = false;
    
    if(argc < 3)
    {
        cerr<<"usage:..."<<endl;
        return 1;
    }
 
 
 
    if(strcmp(argv[1],"-x")==0)
    {
        compress(argv[2]);
    }
 
    

    
    

    
    

    
}
