// COMSC-210 | Lab 17 | Mira Anand
// Module 6, Lesson: Linked Lists, Assignment: Modularize the Linked List Code
// IDE used: Visual Studio Code for Mac

// Program trusts that when user is prompted to add values to the linked list, they will choose values that are not already in the list
// Each value should be different

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
void insertNode(Node *&, float, int);
void deleteList(Node *&);

int main() 
{
    srand(time(0)); // needed as the first line in main() to generate random numbers for the linked list
    
    Node *head = nullptr; // define a pointer for the head of the list and initialize it to nullptr to indicate an empty list
    
    // declaration and initialization of variables section
    int count = 0; // to serve as a counter when creating a linked list with random numbers
    float userTailValue; // will hold the user's choice when they are prompted to enter a value to add to the tail of the list
    float userDeleteValue; // will hold the user's choice when they are prompted to enter a value they wish to delete from the list
    float userInsertValue; // will hold the user's choice when they are prompted to enter a value they wish to insert anywhere in the list
    int userIndexValue; // will hold the user's choice when they are prompted to enter an index value (location) to place userInsertValue

    // create a linked list of size SIZE with random numbers 0-99
    // after the linked list is initially created with random values between 0-99, the user will be able to add float (decimal) values and negative values if they like
    for (int i = 0; i < SIZE; i++) 
    {
        int tmp_val = rand() % 100;
        addNodeToHead(head, tmp_val); // addNodeToHead() function call, helps to uniformly add nodes to the linked list
    }
    // output() function call to display the contents of the linked list immediately after creation
    cout << "Here is the linked list that was generated:" << endl;
    output(head);

    // prompt user to enter a value they want to add to the tail of the list
    cout << "Please choose a value that is not in the list yet -" << endl;
    cout << "Please enter a value you would like to add to the tail of the linked list (decimals and negatives are allowed): ";
    cin >> userTailValue;

    // addNodeToTail() function call, will add the user's inputted value to the end of the list
    addNodeToTail(head, userTailValue);
    // output() function call, to display the contents of the now updated list
    cout << endl;
    cout << "Here is the updated linked list after adding a value to the tail:" << endl;
    output(head);

    // prompt user to enter a value they wish to delete from the list
    cout << "Please enter a value from the linked list that you would like to delete: ";
    cin >> userDeleteValue;

    // deleteNode() function call, will delete the user-entered value from the list or will inform the user that the value was not found in the list
    deleteNode(head, userDeleteValue);
    // output() function call, to display the contents of the now updated list
    cout << endl;
    cout << "Here is the updated linked list after deleting a value from the list (if the value entered was found in the list):" << endl;
    output(head);

    // prompt user to enter a value they wish to insert anywhere in the list
    cout << "Please choose a value that is not in the list yet -" << endl;
    cout << "Please enter a value you would like to insert in the linked list (decimals and negatives are allowed, index will be asked next): ";
    cin >> userInsertValue;
    // prompt user to enter index value (location) where they would like to insert userInsertValue
    cout << "Please enter the index value (location) of where you would like to place this value (starts at 1): ";
    cin >> userIndexValue;

    // insertNode() function call, will place user-entered value at user-entered location or will inform the user that the index was not within range
    insertNode(head, userInsertValue, userIndexValue);
    // output() function call, to display the contents of the now updated list
    cout << endl;
    cout << "Here is the updated linked list after inserting a value in the list (if the index entered was within valid range):" << endl;
    output(head);

    // deleteList() function call, will delete the entire linked list
    deleteList(head);
    // output() function call, to display the contents of the now updated list
    cout << "Here is the updated linked list after deleting the entire list:" << endl;
    output(head);

    return 0;
}

// addNodeToHead(Node *& head, float val) function header
// DESCRIPTION: this function will create a new node, set the value of the new node, and add this new node to the front (head) of the list
// this function is called in main() to initially generate a linked list and fill it with random numbers
// ARGUMENTS: Node *& head, which is a pointer to the head of the list and float val, which represents the value being added
// Passing by reference because the linked list will be modified and this modification will also reflect in main()
// RETURNS: nothing, void function. Purpose is to just create a new node with a value and add it to the head of the list
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

// output(Node * head) function header
// retaining this function from starter code
// DESCRIPTION: this function will check if the linked list is empty or not. The contents of the linked list will be neatly outputted to the console
// if there are no contents, the user will be notified with a console message
// ARGUMENTS: Node * head, which is a pointer to the head of the list
// RETURNS: nothing, void function. Purpose is to just output contents of list or tell the user that it is empty
void output(Node * head) 
{
    if (!head) // if list is empty
    {
        cout << "Empty list.\n";
        return; // exit function
    }
    
    int count = 1;
    Node * current = head; // used to start at the beginning of the list and traverse

    // traverse the list and display its contents
    while (current)
    {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    
    cout << endl;
}

// addNodeToTail(Node *& head, float val) function header
// DESCRIPTION: this function will create a new node, set the value of the new node, and add this new node to the end (tail) of the list
// ARGUMENTS: Node *& head, which is a pointer to the head of the list and float val, which represents the value being added
// Passing by reference because the linked list will be modified and this modification will also reflect in main()
// RETURNS: nothing, void function. Purpose is to just create a new node with a value and add it to the tail of the list
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

// deleteNode(Node *& head, float val) function header
// DESCRIPTION: this function will traverse the list to find a value to delete and will delete that value
// deletion will not be performed if the linked list is empty. Function performs a check for that
// deletion will also not be performed if the value being searched for was not found. Function also performs a check for that
// ARGUMENTS: Node *& head, which is a pointer to the head of the list and float val, which represents the value wanting to be deleted
// Passing by reference because the linked list will be modified and this modification will also reflect in main()
// RETURNS: nothing, void function. Purpose is to just search for the value to be deleted, and if successful, delete that value from the list
void deleteNode(Node *& head, float val)
{
    // deleting a linked list requires 2 pointers:
    Node *current = head; // to locate node to be deleted
    Node *previous = nullptr; // points to the node before the one to be deleted

    if (!head) // if linked list is empty. Important to perform this check as validation to ensure we are not deleting from an empty list
    {
        cout << "The linked list is empty. No deletions can be performed." << endl;
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

    if (!previous) // if the value being searched for is found at the head of the list
        head = head->next; // head will now point to the next node
    else // if the value being searched for is NOT found at the head
        previous->next = current->next; // this is the bypass process to bypass the node we want to delete

    delete current; // delete the value we searched for and found
    current = nullptr; // set current to nullptr for good housekeeping
}

// insertNode(Node *& head, float val, int index) function header
// DESCRIPTION: this function will create a new node, set the value of the new node, and add this new node to a certain index within the list
// the value will not be inserted if the index is greater than or less than the size of the list. Function performs a check for that
// if the user wishes to insert the value at the tail (last index of the list), a new index will be created for that value 
// for example, if a list has 8 values, inserting at index 8 will create a new index (9), which is valid since we want the value to be inserted at the tail
// creation of this new index and adding a tail is demonstrating the fact that linked lists can grow and are not a fixed size
// ARGUMENTS: Node *& head, which is a pointer to the head of the list -  float val, which represents the value to be inserted
// Also, int index, which represents the position at which the value should be inserted in the list
// Passing by reference because the linked list will be modified and this modification will also reflect in main()
// RETURNS: nothing, void function. Purpose is to just insert a node at a certain index (as long as the index is valid)
void insertNode(Node *& head, float val, int index)
{
    Node *newNode = new Node; // create a new node
    newNode->value = val; // set value of new node
    newNode->next = nullptr; // set next pointer to nullptr

    // performs a check to make sure the index (where the value should be inserted) is not less than 1 (head of the list)
    if (index < 1)
    {
        cout << "The index you inserted is invalid. Index starts at 1. Cannot be inserted." << endl;
        delete newNode; // delete newNode for good housekeeping
        return; // exit the function
    }

   if (index == 0) // if we want to insert the value at the head
    {
        newNode->next = head; // next will point to head
        head = newNode; // make newNode the head
        return; // exit the function
    }

    Node *current = head; // will be used to traverse list
    Node *previous = nullptr; // will be used to keep a track of the previous node

    // creation of a while loop to traverse the list until we reach the point where the value should be inserted
    int i = 0;
    while (i < index && current)
    {
        previous = current; // keep track of the previous node by updating previous to current
        current = current->next; // current is now updated and points to the next node in the list
        i++;
    }

    if (i < index) // if the index is not within the range of the list size
    {
        cout << "The index you entered exceeds the valid range of the linked list size. Cannot be inserted." << endl;
        delete newNode; // delete newNode for good housekeeping
        return; // exit the function
    }

    if (previous) // if we want to insert the value somewhere other than the head
    {
        previous->next = newNode;
        newNode->next = current;
    }
}

// deleteList(Node *& head) function header
// DESCRIPTION: this function will traverse the list (visit each node) and delete each node
// ARGUMENTS: Node *& head, which is a pointer to the head of the list
// Passing by reference because the linked list will be modified and this modification will also reflect in main()
// RETURNS: nothing, void function. Purpose is to just delete the entire linked list
void deleteList(Node *& head)
{
    Node *current = head; // will be used to traverse list, starts at beginning of list
    Node *nextNode = nullptr; 

    while (current) // traverse list, while current does not hit nullptr
    {
        nextNode = current->next; // head points to next node after current
        delete current;
        current = nextNode; 
    }

    head = nullptr;
}