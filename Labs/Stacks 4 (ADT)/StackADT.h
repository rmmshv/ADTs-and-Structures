/**~*~*~*~*
CIS 22C
Project: Stack ADT - Stack template

Written by: Rimma Esheva
IDE: VS Code
*~*/

#ifndef STACK_ADT
#define STACK_ADT

template <class T>
class Stack
{
private:
    // Structure for the stack nodes
    struct StackNode
    {
      T value;          // Value in the node
      StackNode *next;  // Pointer to next node
    };

    StackNode *top;     // Pointer to the stack top
    int length;

public:
    Stack(); // Constructor
    ~Stack(); // Destructor

    // Stack operations:
    bool push(T);
    T pop();
    T peek();
    bool isEmpty();
    T getLength();
};


/**~*~*~*~*
  Constructor:
  Initializes object of the class.
*~**/
template <class T>
T Stack<T>::Stack() {
    top = NULL;
    length = 0; 
}

/**~*~*~*~*
  Member function push inserts the argument onto
  the stack.
*~**/
template <class T>
bool Stack<T>::push(T item) {
    StackNode *newNode; // Pointer to a new node

   // Allocate a new node and store num there.
   newNode = new StackNode;
   if (!newNode)
       return false;
   newNode->value = item;

   // Update links and counter
   newNode->next = top;
   top = newNode;
   length++;

   return true;
}

/**~*~*~*~*
  Member function pop deletes the value at the top
  of the stack and returns it.
  Assume stack is not empty.
*~**/
template <class T>
T Stack<T>::pop() {
    int item = top->value;
    top = top->next;
    length--;

    return item;
}

/**~*~*~*~*
  Member function peek returns the item at the top of the stack
  without removing it,
*~**/
template <class T>
T Stack<T>::peek() {
    if (length == 0)
        return NULL;
    else
        return top->value;
    
}

/**~*~*~*~*
  Member function isEmpty returns true if stack
  has no items.
*~**/
template <class T>
bool Stack<T>::isEmpty() {
    if (length ==0 )
        return true;
    else
        return false;
}


/**~*~*~*~*
  Member function getLength returns the number
  of items in the stack.
*~**/
template <class T>
T Stack<T>::getLength() {
    return length; 
}

/**~*~*~*~*
  Destructor:
  Traverses the list deleting each node (without calling pop)
*~**/
template <class T>
Stack<T>::~Stack() {
    StackNode *currNode;
    currNode = top;

    while (currNode != Null) {
        top = top->next;
        delete currNode;
        currNode = top;
    }
}

#endif
