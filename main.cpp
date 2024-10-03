// COMSC-210 | Lab 17 | Mira Anand
// Module 6, Lesson: Linked Lists, Assignment: Modularize the Linked List Code
// IDE used: Visual Studio Code for Mac

#include <cstdlib> // needed to generate a random number
#include <ctime> // needed to generate a random number
#include <iostream>
using namespace std;

// declaration and initialization of a const int variable to represent the initial size of the linked list when it is populated with random numbers in main()
const int SIZE = 7;  

// creation of a struct named "Node"
struct Node 
{
    float value; // represents data that will be stored in the node, can be a decimal value
    Node *next; // points to the next node
};

// function prototypes
void addNodeToHead(Node *&, float);
void output(Node *);
void addNodeToTail(Node *&, float);
void deleteNode(Node *&, float);

int main() 
{
    srand(time(0)); // needed as the first line in main() to generate random numbers for the linked list
    
    Node *head = nullptr; // define a pointer for the head of the list and initialize it to nullptr to indicate an empty list
    
    // declaration and initialization of variables section
    int count = 0; // to serve as a counter when creating a linked list with random numbers
    float userTailValue; // will hold the user's choice when they are prompted to enter a value to add to the tail of the list

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) 
    {
        int tmp_val = rand() % 100;
        addNodeToHead(head, tmp_val); // addNodeToHead() function call, helps to uniformly add nodes to the linked list
    }
    output(head); // output() function call to display the contents of the linked list immediately after creation

    // prompt user to enter a value they want to add to the tail of the list
    cout << "Please enter a value you would like to add to the tail of the linked list (decimals are allowed): ";
    cin >> userTailValue;

    // addNodeToTail() function call, will add the user's inputted value to the end of the list
    addNodeToTail(head, userTailValue);
    // output() function call, to display the contents of the now updated list
    cout << "Here is the updated linked list after adding a value to the tail:" << endl;
    output(head);

    // deleting a node
    Node * current = head;
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    current = head;
    Node *prev = head;
    for (int i = 0; i < (entry-1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    // at this point, delete current and reroute pointers
    if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
    output(head);

    // insert a node
    current = head;
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    prev = head;
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;
    output(head);

    // deleting the linked list
    current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    output(head);

    return 0;
}

// function header
// DESCRIPTION:
// ARGUMENTS:
// RETURNS: 
void addNodeToHead(Node *& head, float val)
{
    Node *newNode = new Node; // create a new node
    newNode->value = val; // set value of new node

    if (!head) // if linked list is empty
    {
        head = newNode; // make newNode the head
        newNode->next = nullptr; // next node after newNode should be set to nullptr
    }
    else // if linked list is NOT empty
    {
        newNode->next = head; // next will now point to list's 1st node 
        head = newNode; // head points to newNode
    }
}

// function header
// DESCRIPTION:
// ARGUMENTS:
// RETURNS: 
void output(Node * hd) 
{
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

// function header
// DESCRIPTION:
// ARGUMENTS:
// RETURNS: 
void addNodeToTail(Node *& head, float val)
{
    Node *newNode = new Node; // create a new node
    newNode->value = val; // set value of new node
    newNode->next = nullptr; // set next pointer to nullptr

    if (!head) // if linked list is empty
        head = newNode; // make newNode the head
    else // if linked list is NOT empty
    {
        Node *current = head; // current points to head
        while (current->next) // loop to traverse list to the end
        {
            current = current->next; // current points to next node in the list
        }

        current->next = newNode; // last node is now set to newNode
    }
}

// function header
// DESCRIPTION:
// ARGUMENTS:
// RETURNS: 
void deleteNode(Node *& head, float val)
{
    // deleting a linked list requires 2 pointers:
    Node *current = head; // to locate node to be deleted
    Node *previous = nullptr; // points to the node before the one to be deleted

    if (!head) // if linked list is empty. Important to perform this check as validation to ensure we are not deleting from an empty list
    {
        cout << "ERROR: The linked list is empty. No deletions can be performed." << endl;
        return; // exit the function
    }

    // traverse/search the list for the value to delete
    while (current && current->value != val)
    {
        previous = current; // keep track of the previous node
        current = current->next; // current now points to the next node in the list in order to continue the search
    }

    if (!current) // if the value being searched for was not found. Important to perform this check to provide the user with feedback on their entered value
    {
        cout << "The value you entered to be deleted was not found in the linked list." << endl;
        return; // exit the function
    }
}