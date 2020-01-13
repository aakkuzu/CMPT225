/*
 
 BitStream.h 
 
 Author: Anastasia Akkuzu
 Date: March 20th, 2019
 
 */


#pragma once

#include <fstream>

using namespace std;


const unsigned char BIT_MASK = 1<<7;
const unsigned int BIT_MASK_INT = 1<<31;


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
    
    
    
    char getAChar()
    {
        char c = 0;
        
        for(int i=0; i<8; i++){
            if(getABit()==1){
                c = c | BIT_MASK>>i;
            }
        }
        
        
        return c;
    }
    
    
    char getAnInt()
    {
        int c = 0;
        for(int i=0; i<32; i++){
            if(getABit()==1){
                c = c | BIT_MASK>>i;
            }
        }
        return c;
    }
    
    
    bool eof()
    {
        return file.eof();
    }
    
    
    void close()
    {
        file.close();
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
    
 
    void putAChar(char c)
    {
        for(int i=0; i<8; i++){
            putAbit(c & (BIT_MASK>>i));
        }
    }
    

    void putAnInt(int c)
    {
        for(int i=0; i<32; i++){
            putAbit(c & (BIT_MASK>>i));
        }
    }
    
    
    void close()
    {
        file.close();
    }
    

    
    
    
private:
    
    
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


