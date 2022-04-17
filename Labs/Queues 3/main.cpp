/**~*~*~*
CIS 22C
Project: Queue of strings (pop)

Written by: Rimma Esheva
IDE: VS code
*~*/
#include <iostream>
#include <string>
using namespace std;

class Queue_str
{
private:
   // Structure for the stack nodes
   struct QueueNode {
       string value;        // Value in the node
       QueueNode *next;     // Pointer to next node
   };

   QueueNode *front;          // Pointer to the first node
   QueueNode *rear;           // Pointer to the last node
   int length;                // Number of nodes in the queue

public:
   Queue_str(){ front = rear = NULL; length = 0; }    //Constructor
   //~Queue_str();                                    // Destructor

   // Queue operations
   bool isEmpty() {
       if (length == 0)
        return true;
   }
   bool push(string);
   string pop();
   //string peek(); 
   //string peekRear();
   //int getLength();
};

/**~*~*~*
  Member function push: inserts the argument into the queue
*~**/
bool  Queue_str::push(string item)
{
   QueueNode *newNode; // Pointer to a new node

   // Allocate a new node and store num there.
   newNode = new QueueNode;
   if (!newNode)
       return false;
   newNode->value = item;
   newNode->next = NULL;
   
   // Update links and counter
   if (!front) // front is NULL: empty queue
       front = newNode;
   else
       rear->next = newNode;
       
   rear = newNode;
   length++;

   return true;
}


/**~*~*~*
  Member function dequeue deletes the value at the front
  of the queue and returns it.
  Assume queue has at least one node
*~**/
string Queue_str::pop()
{
    QueueNode *newNode = new QueueNode; // Allocate a new node and store num there.
    
    string item;
    item = front->value;
    newNode = front->next;
    front = newNode;

   return item;
}

int main() {

     Queue_str que;
     string item;
    
    // Push items into the queue till "#" is entered
     cin >> item;
     while (item != "#") {
         que.push(item);
         cin >> item;
     }
     // Once "#" is reached, if queue is not empty, pop and display the items one per line
     if (item == "#") {
         if (que.isEmpty() == true) {
             cout <<"Empty Queue!" <<endl; // If queue is empty, print "Empty Queue!"
         } else {
             while (!que.isEmpty()) {
                 cout <<que.pop() <<endl;
            } 
         }
     }
       
     return 0;
}