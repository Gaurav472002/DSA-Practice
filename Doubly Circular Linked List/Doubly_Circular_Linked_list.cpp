#include <iostream>
using namespace std;

// Node structure for Doubly linked list
class Node
{

public:
    // Variable to hold the data of the node
    int data;
    // Pointer to the next node in the list
    Node *next;

    // Pointer to the previous node in the list
    Node *prev;

    // Constructor to initialize the node with data and next pointer
    Node(int data)
    {   
        // Here both the next and prev pointer of the node will point to itself only
        this->data = data;
        this->next = this;
        this->prev = this;
    }
};

class DoublyCircularLinkedList
{

public:
    // Global head pointer for the linked list
    Node *head;
    DoublyCircularLinkedList()
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

        // Point the next pointer of the new node to the current head
        newNode->next=head;

        // Point the prev pointer of the new node to the last node

        newNode->prev =head->prev;

        // Point the next pointer of the last node to the new head
        head->prev->next=newNode;

        // Point the prev pointer of the current head to the new head

        head->prev=newNode;

        // Update the head of the list;
        head=newNode;
    }

    void insertAtEnd(int data)
    {

        // If there is no node present in the linked list then insert the node at first
        if (!head)
        {
            insertAtFirst(data);
            return;
        }
        
        // Create the new Node;

        Node * lastNode = new Node(data);

        // Point the next pointer of the last node to the head
        lastNode->next=head;

        // Point the prev pointer of the last node to current last node
        lastNode->prev=head->prev;


        
        // Point the next pointer of the current last node to new last node
        head->prev->next=lastNode;

        // Point the prev pointer of the head to the new last node
        head->prev=lastNode;

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

        // Create the new node to insert at the middle
        Node *newNode = new Node(data);

        // Point the next node of the new node to the next node of the current middle node
        newNode->next = temp->next;
        // Point the previous node of the new node to the current middle node
        newNode->prev = temp;

        // Point the next pointer of the current middle node to the new node
        temp->next = newNode;

        // Point the previous pointer of the next node of the current middle node to the new node

        if (newNode->next != head)
        {
            newNode->next->prev = newNode;
        }
    }

    // Function to count the number of nodes in the list

    int countNodes()
    {
        if (!head)
            return 0;

        int count = 0;
        Node *temp = head;
        
        do{
            count++;
            temp = temp->next;
        }while (temp!=head);
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
            newNode->prev = temp;
            temp->next = newNode;
            if (newNode->next != head)
            {
                newNode->next->prev = newNode;
            }
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

        Node *temp=head;

        // If only single node exists
        if(head->next==head){
            delete head;
            head=nullptr;
        }
        
        // Point the next node of the last node to the next node of the current head
        head->prev->next=head->next;

        //point the prev node of the new head to the last node
        head->next->prev=head->prev;

        // Move head to next node

        head=head->next;
        //deattach the current head
        temp->next=nullptr;
        temp->prev=nullptr;

        // Delete the head
        delete(temp);

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
        if (head->next==head)
        {
            delete head;
            head = nullptr;
            cout << "Deleted the last node of the list" << endl;
            return;
        }

        Node * temp=head->prev;

        // Update the next pointer of the second last node to head
        temp->prev->next=head;
        // Update the previous pointer of the head
        head->prev=temp->prev;
        
        // deattach the last node
        temp->prev=nullptr;
        temp->next=nullptr;

        // delete the last node
        delete(temp);

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

        
        do{

            temp = temp->next;
            if (temp->data == ele)
            {
                break;
            }
        }while (temp != head && temp->data != ele);

        // If the element is not found in the list inform the user
        if (temp == head)
        {
            cout << "Sorry the element was not found in the list" << endl;
            return;
        }
        else
        {
            // If element is found

            // Point the next pointer of the previous node to the element after the node to be deleted
            temp->prev->next = temp->next;
            if (temp->next != nullptr)
            {
                // If the next node exists for the node to be deleted then point its previous to current node's previous
                temp->next->prev = temp->prev;
            }

            // Deattach the node to be deleted
            temp->next = nullptr;
            temp->prev = nullptr;
            delete temp;
            cout << "Deleted " << ele << " from the list" << endl;
        }
    }

    // Function to delete the middle node of the list

    void deleteMiddle()
    {

        // Find the count of the nodes

        int count = countNodes();

        if (count == 1)
        {
            deleteFirst();
            return;
        }

        int middle = count / 2;

        if (middle < 1)
        {
            return;
        }

        // reach till the middle node, previous pointer not required for doubly linked lists

        Node *temp = head;

        for (int i = 1; i <= middle; i++)
        {
            temp = temp->next;
        }
        temp->prev->next = temp->next;

        // Edge case when the next node is nullptr
        if (temp->next != nullptr)
        {
            temp->next->prev = temp->prev;
        }

        // Deattach the middle node
        temp->next = nullptr;

        temp->prev = nullptr;

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
        
        do{
            cout << " <-> " << temp->data;
            temp = temp->next;
        }while (temp!=head);

        cout<<endl;
        
    }

    // Destructor for the linked list

    ~DoublyCircularLinkedList()
    {
        
        Node * temp=head;

        do{
            Node * next=temp->next;
            delete temp;
            temp=next;
        }while(temp!=head);
        cout<<"Memory freed"<<endl;
    }
};

int main()
{

    DoublyCircularLinkedList L1;

    L1.insertAtFirst(100);
    L1.insertAtEnd(200);
    L1.insertAtEnd(300);
    L1.insertAtEnd(400);

    // L1.insertAtPosition(250,3);

    // L1.insertAtMiddle(270);

    // L1.deleteFirst();
    // L1.deleteLast();
    // L1.deleteMiddle();
    // L1.deleteElementFromList(4400);

    L1.print();
  
}