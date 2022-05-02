// Implementation file for the LinkedList class
// Written By: A. Student
// Changed By: Rimma Esheva
// IDE: VS code

#include <iostream>
#include "LinkedList.h"

using namespace std;

//**************************************************
// Constructor
// This function allocates and initializes a sentinel node
//      A sentinel (or dummy) node is an extra node added before the first data record.
//      This convention simplifies and accelerates some list-manipulation algorithms,
//      by making sure that all links can be safely dereferenced and that every list
//      (even one that contains no data elements) always has a "first" node.
//**************************************************
LinkedList::LinkedList()
{
    head = new Node; // head points to the sentinel node
    head->next = NULL;
    length = 0;
}

//**************************************************
// The insertNode function inserts a new node in a
// sorted linked list
//**************************************************
void LinkedList::insertNode(College dataIn)
{
    Node *newNode;  // A new node
    Node *pCur;     // To traverse the list
    Node *pPre;     // The previous node
    
    // Allocate a new node and store num there.
    newNode = new Node;
    newNode->college = dataIn;

    // Initialize pointers
    pPre = head;
    pCur = head->next;

    // Find location: skip all nodes whose code is less than dataIn's code
    while (pCur && newNode->college.getCode() > pCur->college.getCode())
    {
        pPre = pCur;
        pCur = pCur->next;
    }
    
    // Insert the new node between pPre and pCur
    pPre->next = newNode;
    newNode->next = pCur;
    
    // Update the counter
    length++;
}

//**************************************************
// The deleteNode function searches for a node
// in a sorted linked list; if found, the node is
// deleted from the list and from memory.
//**************************************************
bool LinkedList::deleteNode(string target)
{
    Node *pCur;       // To traverse the list
    Node *pPre;       // To point to the previous node
    bool deleted = false;
    
    // Initialize pointers
    pPre = head;
    pCur = head->next;

    // Find node containing the target: Skip all nodes whose gpa is less than the target
    while (pCur != NULL && pCur->college.getCode() < target)
    {
        pPre = pCur;
        pCur = pCur->next;
    }
    
    // If found, delete the node
    if (pCur && pCur->college.getCode() == target)
    {
        pPre->next = pCur->next;
        delete pCur;
        deleted = true;
        length--;
    }
    return deleted;
}


//**************************************************
// displayList shows the value
// stored in each node of the linked list
// pointed to by head, except the sentinel node
//**************************************************
void LinkedList::displayList() const
{
     Node *pCur;  // To move through the list

     // Position pCur: skip the head of the list.
     pCur = head->next;

     // While pCur points to a node, traverse the list.
     while (pCur)
     {
         // Display the value in this node.
         cout <<pCur->college;
         
         // Move to the next node.
         pCur = pCur->next;
    }
    cout << endl;
}

//**************************************************
// The searchList function looks for a target college
// in the sorted linked list: if found, returns true
// and copies the data in that node to the output parameter
//**************************************************
bool LinkedList::searchList(string target, College &dataOut) const
{
    bool found = false; // assume target not found
    Node *pCur;         // To move through the list
    
    pCur = head->next;
    while (pCur && pCur->college.getCode() < target) {
        pCur = pCur->next;
    }
    if (pCur && pCur->college.getCode() == target) {
        dataOut = pCur->college;
        found = true;
    }
    
    return found;
}

//**************************************************
// Destructor
// This function deletes every node in the list.
//**************************************************
LinkedList::~LinkedList()
{
    Node *pCur;     // To traverse the list
    Node *pNext;    // To hold the address of the next node
    
    // Position nodePtr: skip the head of the list
    pCur = head->next;
    // While pCur is not at the end of the list...
    while(pCur != NULL)
    {
        // Save a pointer to the next node.
        pNext = pCur->next;
        
        // Delete the current node.
        delete pCur;
        
         // Position pCur at the next node.
        pCur = pNext;
    }
    
    delete head; // delete the sentinel node
}

