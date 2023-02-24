// DSAinCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;


// Node class to represent 
// a node of the linked list. 
class Node {
public:
    int data;
    Node* next;

   // default constructor
    Node() {
        data = 0;
        next = NULL;
    }

//parameterized constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};


// Linked list class to 
// implement a linked list. 
class LinkedList {

    Node* head;

public:
    // Default constructor 
    LinkedList() {
        head = NULL;
    }
    // Function to insert a 
    // node at the end of the 
    // linked list. 
    void insertNode(int);

    // Function to print the 
  // linked list. 
    void printList();


    // Function to delete the 
  // node at given position 
    void deleteNode(int);
    

};



void LinkedList::insertNode(int data) {

    // Create the new Node. 
    Node* newNode = new Node(data);


    // Assign to head 
    if(head == NULL) {
        head = newNode;
        return;
    }
    // Traverse till end of list 
    Node* temp = head;
    while (temp->next != NULL) {
        // Update temp 
        temp = temp->next;
    }

    // Insert at the last. 
    temp->next = newNode;
}


// Function to print the 
// nodes of the linked list. 

void LinkedList::printList() {
    //assigning head address to temp 
    Node* temp = head;


    // Check for empty list. 
    if (head == NULL){
        cout << "Linked List is Empty" << endl;
        return;
        }

    // Traverse the list. 
    while (temp != NULL) {
        cout << temp->data <<" ";
        temp = temp->next;
    }
}

// Function to delete the 
// node at given position 

void LinkedList::deleteNode(int nodeOffset) {

    Node* temp1 = head, * temp2 = NULL;
    int ListLen = 0;

    if (head == NULL) {
        cout << "List is Empty" << endl;
        return;
    }


    //Find length of the linked-list. 
    while (temp1 != NULL) {
        temp1 = temp1->next;
        ListLen++;
        
    }
    cout << ListLen;

    // Check if the position to be 
    // deleted is greater than the length 
    // of the linked list. 
    if (ListLen < nodeOffset) {
        cout << "Index out of range"
            << endl;
        return;
    }

    // Declare temp1
    temp1 = head;
    // Deleting the head. 
    if (nodeOffset == 1) {
        
        // Update head 
        head = head->next;
        delete temp1;
        return;

    }


    // Traverse the list to 
    // find the node to be deleted. 
    while (nodeOffset-- > 1) {
        // Update temp2 
        temp2 = temp1;

        // Update temp1 
        temp1 = temp1->next;
    }

    temp2->next = temp1->next;

    delete temp1;


}



int main()
{
    LinkedList list;

    list.insertNode(1);
    list.insertNode(2);
    list.insertNode(3);
    list.insertNode(4);


    cout << "Elements of the list are:";


    list.printList();
    cout << endl;



    // Delete node at position 2. 
    list.deleteNode(2);

    cout << "Elements of the list are: ";
    list.printList();
    cout << endl;

    return 0;

   // std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
