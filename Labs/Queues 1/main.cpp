/**~*~*~*
CIS 22C
Project: Queue of strings

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
   // string pop();
   string peek() {
       return front->value;
   }
   string peekRear() {
       return rear->value;
   }
   int getLength() {
       return length;
   }
};

/**~*~*
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

int main() {

     Queue_str que;
     string item;

     /*
     Write a loop to enter an unknown number of words.
        The loop stops when you enter "#" As you are entering words,
        they are to be inserted into a queue. 
        Once done, display the number of elements on the first line, 
        the value at the front of the queue on the next line, 
        and the value at the end of the queue on the last line.
     */
    int count = 0; // word counter
    string word;

    cin >> word; // prompt the user for a word
    while (word != "#"){
        count++; // update word counter
        que.push(word);
        cin >> word; 
    }
    if (word == "#") {
        cout <<que.getLength() <<endl;
        if (count > 0) {
            cout <<que.peek() <<endl;
            cout <<que.peekRear() <<endl;
        } else {
            cout <<"Empty Queue!" <<endl;
        }
    }
     return 0;
}