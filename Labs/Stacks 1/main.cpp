/**~*~*~*
CIS 22C
Project: Stack of integers 
   
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
   bool isEmpty() { /* Write your code here */
    if (length == 0) {
        return true;
   }
    else
        return false;
    }
   bool push(int);
   // int pop();
   int peek() {/* Write your code here */ 
   return top->value;

   }
   int getLength() {/* Write your code here */
   
   return length;
   }
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


int main() {

     Stack_int s;
     int item;

     // Get input data from the user
     cout <<"Please enter a number. To exit, press 0 or any negative number. " << endl;

     // Keep pushing new items onto the stack, stop once 0 or <0 num is reached
     while (item > 0) {
         cin >> item;
         if (item <= 0) {
             break;
         }
         s.push(item);
     }
     // Display the number of elements on the first line,
     // the value at the top of the stack on the next line,
     // and display again the number of elements in the stack.
     cout << s.getLength() << endl;
     if (s.isEmpty()) {
        cout << "Empty Stack!" << endl << s.getLength() << endl;
     } else {
         cout << s.peek() << endl << s.getLength() << endl;
     }

     return 0;
}