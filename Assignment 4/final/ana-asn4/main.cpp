#include <iostream>
#include <cstring>
#include <fstream>

#include "FrequencyCounter.h"
#include "HuffmanTree.h"

#include "BitStream.h"

using namespace std;








void compress(char* filename,char * new_name)
{
    FrequencyCounter fc;
    fc.countFile(filename);
       
    HuffmanTree t(fc);

    
    ifstream inps(filename);
    
    OutputBitStream ops(new_name);
    
   
    //t.showLeaves();
    
    t.encode(inps,ops);
    
    ops.close();
    
    
}



void decompress(char* filename,char* new_name)
{
    InputBitStream file(filename);
    
    HuffmanTree t(file);
    
    //t.showLeaves();
    
    ofstream outputfile(new_name);
    
    t.decode(file,outputfile);
    
}





int main(int argc,char* argv[])
{
    bool debug = false;

    
    if(argc < 4)
    {
        cerr<<"usage: huff [-d|-c] source destination"<<endl;
        return 1;
    }
 
 
 
    if(strcmp(argv[1],"-c")==0)
    {
        cout<<"Compressing ...";
        compress(argv[2],argv[3]);
        cout<<" Done!"<<endl;
        return 0;
    }
 
    
    else if(strcmp(argv[1],"-d")==0)
    {
        cout<<"Decompressing ...";
        decompress(argv[2],argv[3]);
        cout<<" Done!"<<endl;
        return 0;
    }
    
    cerr<<"usage: huff [-d|-c] source destination"<<endl;
    return 1;
    
    
    
    
    
    
    
    
    
    
    
}
