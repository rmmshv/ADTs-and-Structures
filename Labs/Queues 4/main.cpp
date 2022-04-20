/**~*~*~*
CIS 22C
Project: Queue ADT

Written by:
IDE:
*~*/

#include <iostream>
#include <string>

#include "QueueADT.h"


using namespace std;

int main() {

    QueueADT<string> que_str; // Create the first queue (strings)
    QueueADT<double> que_double; // Create the second queue (doubles)
    string item;
    double num;


    // Write a loop to enter an unknown number of names (assume one word strings).
    // The loop stops when you enter #.
    // As you are entering names, they are to be inserted into the first queue.
    cin >> item;
    if (item == "#") {
        cout <<"Empty Queue!" <<endl;
    } else {
        while (item != "#") {
            que_str.push(item);
            cin >> item;
        }
    
    // Test the getLength function: - display the number of elements in the first queue
    cout <<que_str.getLength() <<" ";

    // Test the getLength function: - display the number of elements in the second queue
    // (it should be 0)
    cout <<que_double.getLength() <<endl ;
    // Write another loop to enter the number of units (double) into a parallel queue. 
    int len = que_str.getLength();
    cin >> num;
    for (int i = 0; i < len; i++) {
        que_double.push(num);
        cin >> num;
    }

    // Saving front and rear que items into variables to print later.
    string top = que_str.peek();
    int back = que_double.peekRear();

    // Display the two queues in parallel.
    
    for (int i = 0; i < len; i++) {
        cout <<que_str.pop() << " " << que_double.pop() <<endl;
    }
    // Display the front element in the first queue
    cout <<top <<endl;

    // Display the rear element in the second queue
    cout <<back <<endl;
    }
    return 0;
}
