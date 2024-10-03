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
    float value; // represents data that will be stored in the node
    Node *next; // points to the next node
};

// function prototypes
void addNodeToHead(Node *&, int);
void output(Node *);

int main() 
{
    srand(time(0)); // needed as the first line in main() to generate random numbers for the linked list
    
    Node *head = nullptr; // define a pointer for the head of the list and initialize it to nullptr to indicate an empty list
    
    // declaration and initialization of variables section
    int count = 0; // to serve as a counter when creating a linked list with random numbers

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) 
    {
        int tmp_val = rand() % 100;
        addNodeToHead(head, tmp_val); // addNodeToHead() function call, helps to uniformly add nodes to the linked list
    }
    output(head); // output() function call to display the contents of the linked list immediately after creation

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
void addNodeToHead(Node *& head, int val)
{
    Node *newNode = new Node; // create a new node
    newNode->value = val; // set value of new node

    if (!head) // if linked list is empty
    {
        
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