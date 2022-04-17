/**~*~*~*
CIS 22C
Project: Stack ADT

Written by: Rimma Esheva
IDE: VS Code
*~*/

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

#include "StackADT.h"

using namespace std;

void printInfo();

//template <class T>
void inputFile(string file);


int main()
{
    printInfo();

    string filename[] = {"in1.txt", "in2.txt", "in3.txt", ""};
    //cout << "Enter input file name: " << endl;
    //string filename;
    //getline(cin, filename); // assume valid
    
    // print the stack
    for (int i = 0; filename[i] != ""; i++){
        inputFile(filename[i]);
    }

    return 0;
}

/**~*~*~*~*~
This function displays the project's title
*~*/
void printInfo()
{
    cout << " ~*~ Project: Stack ADT ~*~ " << endl;
}
/**~*~*~*~*~
This function processes input file
*~*/
//template <class T>
void inputFile(string filename) {
    Stack<int> stack;
    ifstream fin(filename);
    int num;

    // print input file name
    cout << "Enter input file name: " << endl;
    getline(cin, filename);
    cout <<"\nInput File: " <<filename <<endl;

    if (!fin.is_open()){
        cout <<"There was an error opening \"" <<filename <<"\" Exiting." <<endl;
        exit(EXIT_FAILURE); 
    } else {    
    while (fin >> num){
        //If we read 0, display the number of elements in the stack.
        if (num == 0){ 
            cout <<"Count: " << stack.getLength() <<endl; 
        }
        
        //If we read 1, display the element at the top of the stack.
        if (num == 1){
            if(!stack.isEmpty())
                cout <<"Top: " <<stack.peek() <<endl;
            else 
                cout <<"Empty" <<endl;
        }
        
        //If we read a positive number we push it onto the stack
        if (num > 1){
            stack.push(num);
        }

        //If we read a negative number, we pop and print as many values from the stack as the absolute value of the negative number.
        //If there are fewer numbers in the stack, print "Error". The stack does not change.
        if (num < 0) {
            if (stack.getLength() > abs(num)) {
                cout <<"Stack: ";
                for (int i = 0; i < abs(num); i++){
                    cout << stack.pop() <<" ";
                }
                cout <<endl;
            } else {
                cout <<"Error" <<endl;
            }
        }
    }
    
    //When the end of the file is detected, print "Stack: "
    // and pop and print the items left in the stack, if any, or "Empty" otherwise.
    if (!stack.isEmpty()){
        cout <<"Stack: ";
        while (!stack.isEmpty()){
            cout <<stack.pop() <<" ";
    } 
    cout <<endl;
    } else {
        cout <<"Empty" <<endl;
    }
    fin.close();
    }
}