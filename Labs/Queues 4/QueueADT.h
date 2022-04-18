/**~*~*~*
CIS 22C
Project: Queue ADT

Written by: Rimma Esheva
IDE: VS Code
*~*/

#ifndef STACK_ADT
#define STACK_ADT

template <class T>
class QueueADT 
{
private:
   // Structure for the stack nodes
   struct QueueNode {
       T value;        // Value in the node
       QueueNode *next;     // Pointer to next node
   };

   QueueNode *front;          // Pointer to the first node
   QueueNode *rear;           // Pointer to the last node
   int length;   

public:
    QueueADT() {front = rear = NULL; length = 0 }    //Constructor
   //~Queue_str();                                    // Destructor        

   // Queue operations
   bool isEmpty() { if (length == 0) return true; }
   bool push(T);
   T pop();
   T peek() { return front->value; }
   T peekRear() { return rear->value; }
   TgetLength() { return length; }
};

/**
 * Member function push inserts the argument 
 * onto the queue.
 * */
template <class T>
bool QueueADT<T>::push(T arg) {
    QueueADT *newNode; // Pointer to a new node

    // Allocate a new node and store argument there
    newNode = new QueueADT;
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
    T item = front->value;
    QueueADT *newNode = new QueueADT;
    newNode = front->next;
    front = newNode;

    return item;
}

#endif