#include <iostream>
using namespace std;

// Node structure for singly linked list
class Node
{

public:
    // Variable to hold the data of the node
    int data;
    // Pointer to the next node in the list
    Node *next;

    // Constructor to initialize the node with data and next pointer
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList
{

public:
    // Global head pointer for the linked list
    Node *head;
    LinkedList()
    {

        // Initialize the head for the linkedlist
        head = nullptr;
        cout << "Linked List Initialized" << endl;
    }

    // Function to insert a new node at the start of the linked list
    void insertAtFirst(int data)
    {

        // First create a new node

        Node *newNode = new Node(data);
        cout << "Inserted node: " << data << " at the beginning " << endl;
        // If this is the first node of the linked list make it the head
        if (!head)
        {
            head = newNode;
            return;
        }

        // Point the next pointer of the new Node to the current head
        newNode->next = head;
        // Make the new node as the head
        head = newNode;
    }

    void insertAtEnd(int data)
    {

        // If there is no node present in the linked list
        if (!head)
        {
            insertAtFirst(data);
            return;
        }
        // To insert a node at the end of the linked list first we will have to reach at the last node

        Node *temp = head;

        // Traverse to the last node of the linked list
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        // create the new node;

        Node *lastNode = new Node(data);

        // pointer the next pointer of the last node to this node;
        temp->next = lastNode;

        cout << "Inserted node: " << data << " at the end " << endl;
    }

    // Function to insert a node at the middle of the linked list

    void insertAtMiddle(int data)
    {
        int count = countNodes();
        int middle = count / 2;

        if (middle == 0)
        {
            insertAtFirst(data);
            return;
        }

        Node *temp = head;
        for (int i = 1; i < middle; ++i)
        {
            temp = temp->next;
        }

        Node *newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Function to count the number of nodes in the list

    int countNodes()
    {
        if (!head)
            return 0;

        int count = 0;
        Node *temp = head;
        while (temp)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Function to insert a node at the specific position in a linked list

    void insertAtPosition(int data, int pos)
    {

        int count = countNodes();

        if (pos < 1)
        {
            cout << "Invalid position" << endl;
            return;
        }

        else if (pos == 1)
        {
            // Insert the node at first if the position is one
            insertAtFirst(data);
            return;
        }

        else if (pos == count + 1)
        {
            insertAtEnd(data);
            return;
        }
        else if (pos > count + 1)
        {
            cout << "Position out of bounds" << endl;
            return;
        }
        else
        {

            // reach to the node before the required position

            int counter = 1;

            Node *temp = head;
            while (counter != pos - 1)
            {
                counter++;
                temp = temp->next;
            }

            // Create the new node

            Node *newNode = new Node(data);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Function to delete the first node of the linked list

    void deleteFirst()
    {
        if (!head)
        {
            cout << "Linked list does not exists" << endl;
            return;
        }

        Node *temp = head;
        // Update the head to the second node
        head = head->next;

        // delete the first node
        delete (temp);

        cout << "Deleted the first node of the list" << endl;
    }

    // Function to delete the last node of the list

    void deleteLast()
    {
        if (!head)
        {
            cout << "Linked list does not exists" << endl;
            return;
        }

        // if there is only one node in the list
        if (!head->next)
        {
            delete head;
            head = nullptr;
            cout << "Deleted the last node of the list" << endl;
            return;
        }

        // Traverse to the second last node to delete the last node
        Node *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        Node *lastNode = temp->next;

        // point the next pointer of the second node to null
        temp->next = nullptr;

        // delete the last node
        delete (lastNode);

        cout << "Deleted the last node of the list" << endl;
    }

    // Function to delete a specific element from the list

    void deleteElementFromList(int ele)
    {

        if (ele == head->data)
        {
            deleteFirst();
            return;
        }

        // Find the element in the list and keep track of the previous node

        Node *temp = head;
        Node *prev = nullptr;

        while (temp != nullptr && temp->data != ele)
        {
            prev = temp;
            temp = temp->next;
            if (temp->data == ele)
            {
                break;
            }
        }

        // If the element is not found in the list inform the user
        if (temp == nullptr)
        {
            cout << "Sorry the element was not found in the list" << endl;
            return;
        }
        else
        {
            // If element is found
            prev->next = temp->next;
            temp->next = nullptr;
            delete temp;
        }
    }

    // Function to delete the middle node of the list

    void deleteMiddle()
    {

        // Find the count of the nodes

        int count = countNodes();

        int middle = count / 2;

        if (middle < 1)
        {
            return;
        }

        // reach till the middle node and it's previous node;

        Node *temp = head;
        Node *prev = nullptr;

        for (int i = 1; i <= middle; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        temp->next = nullptr;
        delete temp;

        cout << "Deleted the middle node of the list" << endl;

    }

    // Function to print the nodes of the singly linked list
    void print()
    {

        if (!head)
        {
            cout << "Sorry the linked list is empty can't print anything";
            return;
        }

        // Traverse through the linked list and print the nodes
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL";
        cout << endl;
    }

    // Destructor for the linked list

    ~LinkedList()
    {
        Node *temp = head;

        while (temp)
        {
            Node *currNext = temp->next;
            delete temp;
            temp = currNext;
        }
        cout << "Memory for the linked list freed" << endl;
    }
};

int main()
{

    LinkedList L1;

    L1.insertAtFirst(100);
    L1.insertAtEnd(200);
    L1.insertAtEnd(300);
    L1.insertAtEnd(400);
    L1.insertAtEnd(500);

    L1.print();

    // L1.deleteFirst();
    // L1.print();
    // L1.deleteLast();
    // L1.print();
    // L1.deleteMiddle();

    L1.deleteElementFromList(100);
    L1.print();
}