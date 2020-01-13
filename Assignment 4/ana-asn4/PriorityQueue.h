#pragma once
/*
 * PriorityQueue.h
 *
 * Description: Priority Queue, taken from the past assignments.
 * Class Invariant: The elements stored in this Priority Queue are always sorted.
 *
 * Author: Inspired by Frank M. Carrano and Tim Henry (textbook).
 * Modified: March 2019
 *
 */


#include <iostream>
#include <exception>
#include "Node.h"


using namespace std;


class EmptyDataCollectionException: public exception {};



template <class T>  // We can use T, ElementType or other names as a placeholder
class PriorityQueue {

private:

   Node<T>* head;      // Pointer to first node in the chain
   int elementCount;   // Current count of list items

/* You can add private methods to this class */

public:

   // Default Constructor
   PriorityQueue();

   // Destructor
   ~PriorityQueue();

   // Description: Returns the number of elements in the Priority Queue.
   // Time Efficiency: O(1)
   int getElementCount() const;

   // Description: Returns "true" is this Priority Queue is empty, otherwise "false".
   // Time Efficiency: O(1)
   bool isEmpty() const;

   // Description: Inserts newElement in sort order.
   //              It returns "true" if successful, otherwise "false".
   // Precondition: This Priority Queue is sorted.
   // Postcondition: Once newElement is inserted, this Priority Queue remains sorted.
   // Time Efficiency: O(n)
   bool enqueue(const T& newElement);

   // Description: Removes the element with the "highest" priority.
   //              It returns "true" if successful, otherwise "false".
   // Precondition: This Priority Queue is not empty.
   // Time Efficiency: O(1)
   bool dequeue();

   // Description: Returns the element with the "highest" priority.
   // Precondition: This Priority Queue is not empty.
   // Postcondition: This Priority Queue is unchanged.
   // Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
   // Time Efficiency: O(1)
   T peek() const throw(EmptyDataCollectionException);
   
   
   template <class E>
   friend std::ostream& operator<< (std::ostream& stream, const PriorityQueue<E>& pq);
   

}; // end PriorityQueue



// Implementation



//  Constructor

template<typename T> PriorityQueue<T>::PriorityQueue()
{
    this->head = NULL;
    this->elementCount = 0;
}




//  Deconstructor

template<typename T> PriorityQueue<T>::~PriorityQueue()
{
    while(this->isEmpty() != true){
        this->dequeue();
    }
    
    
}


//  Gets the element amount in the Priority Queue

template<typename T> int PriorityQueue<T>::getElementCount() const
{
    return this->elementCount;
}


//  Checks to see if the Priority Queue is empty

template<typename T> bool PriorityQueue<T>::isEmpty() const
{
    if(this->head == NULL && this->elementCount == 0){
        return true;
    }
    else{
        return false;
    }
}


//  Enqueues an item into the Priority Queue

template<typename T> bool PriorityQueue<T>::enqueue(const T& newElement)
{
    Node<T> * newNode = new Node<T>(newElement, NULL);
    
    if(this->isEmpty() == true){
        this->head = newNode;
    }
    else if(this->head->getData() > newElement){
        Node<T>* oldHead = this->head;
        this->head = newNode;
        newNode->setNext(oldHead);
    }
    
    else{
        Node<T>* current;
        
        for(current = this->head; current->getNext() != NULL; current = current->getNext()){
            if(current->getNext()->getData() > newElement){
                break;
            }
        }
        
        Node<T>* oldNext = current->getNext();
        current->setNext(newNode);
        newNode->setNext(oldNext);
    }
    
    this->elementCount += 1;
    return true;
}


// Dequeues an item from the Priority Queue

template<typename T> bool PriorityQueue<T>::dequeue()
{
    if(this->isEmpty()==true){
        return false;
    }
    
    Node<T> * current = this->head;
    Node<T> * newHead = current->getNext();
    this->head = newHead;
    delete current;
    this->elementCount -= 1;
    return true;
        
    
}


//  Peeks at the first item int he Priority Queue

template<typename T> T PriorityQueue<T>::peek() const throw(EmptyDataCollectionException)
{
    if(this->isEmpty()){
        throw EmptyDataCollectionException();
    }
    
    return this->head->getData();
}


//Overloading '<<' operator

template<typename E>
ostream& operator<< (ostream& os, const PriorityQueue<E>& pq){

    os<<"[ ";
    for(Node<E>* current = pq.head; current != NULL; current = current->getNext()){
        os<< current->getData() << ", "<<endl;
    }
    os<<" ]";
    
    return os;
}


//  End of implementation

