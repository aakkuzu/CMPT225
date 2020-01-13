/*
 Huffmantree.h
 
 Author: Anastasia Akkuzu
 Date: March 20th, 2019
 */



#pragma once

#include <cstring>
#include <cstdlib>

#include "FrequencyCounter.h"
#include "PriorityQueue.h"
#include "BitStream.h"




class HuffNode{
    
public:    
    HuffNode(HuffNode* child1, HuffNode* child2)
        :frequency(child1->frequency+child2->frequency)
        ,lchild(child1)
        ,rchild(child2)
    {
        containedChars = new char[NUMBER_OF_CHARS]; 
        strcpy(containedChars,child1->containedChars);
        strcat(containedChars,child2->containedChars);
        
    }
    
    HuffNode(int freq, char charact)
        :frequency(freq)
        ,lchild(NULL)
        ,rchild(NULL)
    {
        containedChars = new char[2];
        containedChars[0] = charact;
        containedChars[1] = '\0';
    }
    
  
  
    bool isLeaf()
    {
        return lchild != NULL && rchild != NULL;
    }
  
  
    
    int frequency;
    HuffNode* lchild;
    HuffNode* rchild;
    char* containedChars;

    
  
};


// I can't get the pointers to compare otherwise
class NodeCompartor
{
public:
    
    NodeCompartor(HuffNode* node)
        :subject(node)
        {}
    
    ~NodeCompartor(){
    }
    
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
        
        leaves.import(subtrees);
        
        root = mkTree(subtrees);
        
    }
    
    
    
    HuffmanTree(InputBitStream& input)
    {
        loadCharList(leaves,input);
        
        PriorityQueue<NodeCompartor> subtrees;
        subtrees.import(leaves);
        
        root = mkTree(subtrees);
    }
    
    
    
    
    void encode(ifstream& input,OutputBitStream& output)
    {
        writeTree(output);
        
        //cout<<"!"<<leaves.getElementCount()<<"!";
        
        char myChar;
        while(input.get(myChar))
        {
            writeEncodedChar(output, myChar);
        }
        
        
    }
    
    void decode(InputBitStream& input, ofstream& output){
    
        
        
        while(!input.eof()){
            
            HuffNode* current = root;
            while(current->isLeaf()){
                if(input.getABit()==1){
                    current = current->lchild;
                } else {
                    current = current->rchild;
                }
            }
            
            output<<current->containedChars[0];
        }
        
    }
    
    
    
    
    void showLeaves()
    {
        PriorityQueue<NodeCompartor> subtrees;
        subtrees.import(leaves);
        
        while(!subtrees.isEmpty())
        {
            cout<<(int)subtrees.peek().subject->containedChars[0]<<":"
                <<subtrees.peek().subject->frequency<<"-";
            subtrees.dequeue();
        }
        
        cout<<endl;
    }
    
    
private:
    
    
    HuffNode* mkTree(PriorityQueue<NodeCompartor>& subtrees)
    {
        while(subtrees.getElementCount()>1)
        {
            HuffNode* child1 = subtrees.peek().subject;
            subtrees.dequeue();
            HuffNode* child2 = subtrees.peek().subject;
            subtrees.dequeue();
            
            HuffNode* new_node = new HuffNode(
               child1,
               child2
            );
            
            subtrees.enqueue(NodeCompartor(new_node));
        }
        
        return subtrees.peek().subject;
    }
    
    
    
    

    
    
    void writeTree(OutputBitStream& output)
    {
        PriorityQueue<NodeCompartor> leavesCopy;
        leavesCopy.import(leaves);
        
        output.putAnInt(leavesCopy.getElementCount());
        
        
        while(!leavesCopy.isEmpty())
        {
            HuffNode* node = leavesCopy.peek().subject;
            leavesCopy.dequeue();
            
            output.putAChar(node->containedChars[0]);
            output.putAnInt(node->frequency);
        }
        
    }
    
    
    void writeEncodedChar(OutputBitStream& output, char c)
    {
        HuffNode* current = root;
        while(current->isLeaf()){
            
            if(current->lchild!=NULL && strchr(current->lchild->containedChars,c)){
                output.putAbit(1);
                current = current->lchild;
            }
            
            else if(current->rchild!=NULL && strchr(current->rchild->containedChars,c)){
                output.putAbit(0);
                current = current->rchild;
            }
            else
            {
                cerr<<"This should never happen"<<endl;
                exit(0);
            }
        }
        
        
    }
    
    
    
    
    
     void loadCharList(PriorityQueue<NodeCompartor>&pq, InputBitStream& bs)
     {
        int charCount = bs.getAnInt();
        
        //cout<<"!"<<charCount<<"!";
        
        
        for(int i =0; i<charCount; i++){
            char c = bs.getAChar();
            int count = bs.getAnInt();
            
            pq.enqueue(NodeCompartor(new HuffNode(count,c)));
        }
     }
    
    
    
    
    HuffNode* root;
    
    PriorityQueue<NodeCompartor> leaves; 
    
};


