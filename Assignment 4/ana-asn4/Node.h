/*
 * Node.h
 *
 * Description: Node Class Template
 * Class Invariant:
 *
 * Author: Anastasia Akkuzu
 * Modified: February 21, 2019
 *
 */ 

#pragma once

#include <iostream>


using namespace std;

template <class T>

class Node {
private:
    T data;
    Node<T> * next;
   
    
public:
    Node();
    
    Node(const T& data, Node<T> * next);
    
    void setData(const T& data);
    
    void setNext(/*const*/ Node<T> * next);
    
    T getData() const;
    
    Node<T> * getNext() const;
    
};



// Implementation


//  Constructors

template<typename T> Node<T>::Node(){
    this->data = NULL;
    this->next = NULL;
}



template<typename T> Node<T>::Node(const T& data, 
Node<T>* next)
    :data(data),next(next)
{
    this->data = data;
    this->next = next;
}



//  Sets the next pointer for the current node

template<typename T> void Node<T>::setNext(/*const*/ 
Node<T>* next){
    this->next = next;
}


//  Sets the data for the current node

template<typename T> void Node<T>::setData(const T& 
data){
    this->data = data;
}


//  Gets the next pointer for the current node

template<typename T> Node<T> * Node<T>::getNext() 
const{
    return this->next;
}


//  Gets the data for the current node

template<typename T> T Node<T>::getData() const{
    return this->data;
}

