/**~*~*~*
CIS 22C
Project: Stack of integers (pop)

Written by: Rimma Esheva
IDE: VS Code
*~*/
#include <iostream>
using namespace std;

class Stack_int
{
private:
   // Structure for the stack nodes
   struct StackNode {
       int value;           // Value in the node
       StackNode *next;     // Pointer to next node
   };

   StackNode *top;          // Pointer to the stack top
   int length;

public:
   Stack_int(){ top = NULL; length = 0; }    //Constructor
   //~Stack_int();                            // Destructor

   // Stack operations
   bool isEmpty(); /* Write your code here */
   bool push(int);
   int pop();
   int peek();
   int getLength();
};

/**~*~*~*
  Member function push: pushes the argument onto the stack.
*~**/
bool Stack_int::push(int item)
{
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

/**~*~*~*
  Member function pop pops the value at the top
  of the stack off, and returns it
  Assume stack is not empty
*~**/
/* Define the pop function */
int Stack_int::pop() {
    int item = top->value;
    top = top->next;
    --length;

    return item;

}

int main() {

     Stack_int s;
     int item;

     // Get input data to push onto the stack. Stop once 0 or <0 num is entered.
     while (item > 0) {
         cin >> item;
         if (item <= 0) {
             break;
         }
         s.pop();
     }
     return 0;
}