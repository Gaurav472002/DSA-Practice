#include<iostream>
using namespace std;

// Structure of the node of the linked list for the stack

class Node{
    public:
    int data;
    Node * next;

    
    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
};

// Structure for the stack using linked list
class Stack{

    Node * top;

    public:

    Stack(){
        top=nullptr;

        cout<<"Stack initialized"<<endl;
    }
    ~Stack(){
        while(!isEmpty()){
            pop();
        }
        cout<<"Memory freed"<<endl;
    }

    // Function to check if the stack is empty or not
    bool isEmpty(){

        return top==nullptr;
    }

    // Function to insert an element into the stack
    void push(int ele){

        // Create the new node for the stack

        Node * newElement = new Node(ele);

        // Point the new node to the current top
        newElement->next=top;
        // Update the top pointer of the stack

        top=newElement;

        cout<<"Pushed element: "<<ele<<" to the stack successfully"<<endl;
    }

    // Function to pop an element from the stack
    int pop(){

        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }

        // Get hold of the current top element

        Node *temp=top;

        // store the element of the topmost node
        int ele=temp->data;

        // update the top of the stack

        top=top->next;

        // delete the top node
        delete temp;
        
        cout<<" Popped element: "<<ele<<" from the stack"<<endl;
        return ele;
    }

    // Function to peek onto the topmost element of the stack

    int peek(){

        if(isEmpty()){
            cout<<"The stack is empty"<<endl;
            return -1;
        }

        int ele=top->data;

        cout<<"The topmost element of the stack is "<<ele<<endl;
        return ele;
    }


    // Function to print the elements of the stack

    void print(){

        if(isEmpty()){
            cout<<"The stack is empty"<<endl;
            return;
        }

        Node * temp=top;

        while(temp){
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }

    
};


int main(){

    Stack S1;

    S1.push(100);
    S1.push(200);
    S1.push(300);
    S1.push(400);
    S1.peek();
    S1.print();
    S1.pop();
    S1.print();
    S1.pop();
    S1.print();
    S1.pop();
    S1.print();
    S1.pop();
    S1.print();
    return 0;
}