#pragma once

#include <fstream>

using namespace std;

//TODO split in to two files?

const unsigned char BIT_MASK = 1<<7;


class InputBitStream{
public:
    
    InputBitStream(char *filename)
        :file(filename)
        ,positionInByte(0)
    {
        currentByte = file.get();
    }

    bool getABit(){
        bool out = currentByte & (BIT_MASK >> positionInByte);
        
        prepareNextBit();
        
        return out;
    }
    
    
    bool eof()
    {
        return file.eof();
    }
    
    
private:
    
    void prepareNextBit(){
        if(positionInByte<7){
            positionInByte++;
        }
        else{
            positionInByte = 0;
            currentByte = file.get();
        }
    }
    
    
    ifstream file;
    int positionInByte;
    char currentByte;
    
};




class OutputBitStream{
public:
    
    OutputBitStream(char *filename)
        :file(filename)
        ,positionInByte(0)
    {
        currentByte = 0;
    }

    void putAbit(bool bit){
        
        if(bit){
            //cout<<"["<<int(currentByte)<<":";
            currentByte = currentByte | (BIT_MASK >> positionInByte);
            //cout<<""<<int(currentByte)<<"]";
        }
        
        update();
    }
    
    
    
private:
    
    // write if necessary or just update the buffer
    void update(){
       
        if(positionInByte == 7){
            file<<currentByte;
            currentByte = 0;
            positionInByte = 0;
        }
        else{
            positionInByte++;
        }
    }
    
    
    ofstream file;
    int positionInByte;
    char currentByte;
    
};


