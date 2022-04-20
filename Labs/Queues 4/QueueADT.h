/**~*~*~*
CIS 22C
Project: Queue ADT

Written by: Rimma Esheva
IDE: VS Code
*~*/
#include <stdio.h>
#ifndef STACK_ADT
#define STACK_ADT

template <class T>
class QueueNode{
public:
    T value;        // Value in the node
    QueueNode *next;     // Pointer to next node

    QueueNode(T value) {
        this->value = value;
        next = 0;
    }
};


template <class T>
class QueueADT {
public:
   QueueNode<T> *front;          // Pointer to the first node
   QueueNode<T> *rear;           // Pointer to the last node
   int length;   


    QueueADT() {front = rear = 0; length = 0; }    //Constructor
    ~QueueADT();                                         

   // Queue operations
   bool isEmpty() { return (length == 0); }
   bool push(T);
   T pop();
   T peek() { return front->value; }
   T peekRear() { return rear->value; }
   int getLength() { return length; }
};

/**
 * Member function push inserts the argument 
 * onto the queue.
 * */
template <class T>
bool QueueADT<T>::push(T arg) {
    QueueNode<T> *newNode; // Pointer to a new node

    // Allocate a new node and store argument there
    newNode = new QueueNode<T>(arg);
    if (!newNode)
        return false;
        newNode->value = arg;
        newNode->next = NULL;

    // Update links and counter
    if (!front) // front is NULL, empty queue
        front = newNode;
    else
        rear->next = newNode;

    rear = newNode;
    length++;

    return true;
    
}

/**
 * Member function pop deletes the value at the front 
 * of the queue and returns it.
 * Assume queue is not empty.
 * */
template <class T>
T QueueADT<T>::pop() {
    QueueNode<T> *newNode;
    
    T item = front->value;
    newNode = front->next;
    front = newNode;

    return item;
}

/**
 * Destructor:
 * Traverses the queue deleting each node
 * */
template <class T>
QueueADT<T>::~QueueADT(){ 
    QueueNode<T> *temp;
    while(front) {
        temp = front;
        front = front->next;
        delete temp;
    }
    front = rear = 0;
}

#endif