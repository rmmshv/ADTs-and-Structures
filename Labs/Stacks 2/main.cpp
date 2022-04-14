/**~*~*~*
CIS 22C
Project: Stack of integers (Destructor)

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
   int length;              // Number of nodes

public:
   Stack_int(){ top = NULL; length = 0; }    //Constructor
   ~Stack_int();                             // Destructor

   // Stack operations
   // bool isEmpty();
   bool push(int);
   // int pop();
   // int peek();
   // int getLength();
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
   Destructor
*~**/
Stack_int::~Stack_int()
{
   StackNode *currNode;

   // Position nodePtr at the top of the stack.
   currNode = top;

   // Traverse the list deleting each node.
   while (currNode) 
   {
      cout << currNode->value << " - deleted!" << endl;
      
      // Allocate current node to a temporary variable, delete once done iterating through
      StackNode* temp = currNode;
      currNode = currNode->next;
      delete temp;
      temp = NULL;
      
   }
   cout << "Empty stack!" << endl;
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
         s.push(item);
     }
     
     return 0;
}