#pragma once

#include <cstring>

#include "FrequencyCounter.h"
#include "PriorityQueue.h"
#include "BitStream.h"




class HuffNode{
    
public:    
    HuffNode(int freq,char* contained_chars,HuffNode* child1, HuffNode* child2)
        :frequency(freq)
        ,lchild(child1)
        ,rchild(child2)
        ,containedChars(contained_chars)

    {}
    
    HuffNode(int freq, char charact)
        :frequency(freq)
        ,lchild(NULL)
        ,rchild(NULL)
    {
        containedChars = new char[2];
        containedChars[0] = charact;
        containedChars[1] = '\0';
    }
    
  
  
    // No need to make them private and make getters and setters since they can't be
    // modified
    int frequency;
    HuffNode* lchild;// Only used if node is not a leaf
    HuffNode* rchild;// Only used if node is not a leaf
    char* containedChars;

    
  
};


// I can't get the pointers to compare otherwise
struct NodeCompartor
{
    
    NodeCompartor(HuffNode* node)
        :subject(node)
        {}
    
    bool operator>(NodeCompartor rhs)
    {
        return subject->frequency > rhs.subject->frequency;
    }
    
    
    HuffNode* subject;
};




class HuffmanTree
{
    
public:
    
    
    
    HuffmanTree(FrequencyCounter fc)
    {
        PriorityQueue<NodeCompartor> subtrees;
        
        for(int i=0;i<NUMBER_OF_CHARS;i++)
        {
            if(fc.getCount((char)i)>0){
                subtrees.enqueue(NodeCompartor(new HuffNode(fc.getCount(i),(char)i)));
            }
        }
        
        while(subtrees.getElementCount()>1)
        {
            HuffNode* child1 = subtrees.peek().subject;
            subtrees.dequeue();
            HuffNode* child2 = subtrees.peek().subject;
            subtrees.dequeue();
            
            char* allChars = new char[NUMBER_OF_CHARS]; 
            strcpy(allChars,child1->containedChars);
            strcat(allChars,child2->containedChars);
            
            HuffNode* new_node = new HuffNode(
               child1->frequency+child2->frequency,
               allChars,
               child1,
               child2
            );
            
            subtrees.enqueue(NodeCompartor(new_node));
        }
        
        root = subtrees.peek().subject;
    }
    
    
    
    HuffmanTree(ifstream& input)
    {
        //read from file
    }
    
    
    
    
    void encode(ifstream& input,OutputBitStream& output)
    {
        writeTree(input);
        
        char myChar;
        while(input.get(myChar))
        {
            writeEncodedChar(output, myChar);
        }
        
        // TODO make sure to have an eof char at the end
    }
    
    void decode();
    
    
private:
    
    
    
    
    
    
    
    
   
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    // CONTINUE HERE: implement these, then move to implementing the decoding 
    //of the tree starting from the second constructor
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    void writeTree(ifstream& input)
    {
        
    }
    
    
    void writeEncodedChar(OutputBitStream& output, char c)
    {
        
    }
    
    
    
    
    
    
    HuffNode* root;
    
};


