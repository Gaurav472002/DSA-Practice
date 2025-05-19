#include<iostream>
using namespace std;

// Structure for the node present in the queue

class Node{
    public:

    int data;
    Node *next;

    
    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
};


class Queue{

    Node * front;
    Node * rear;

    public:
    Queue(){
        front=nullptr;
        rear=nullptr;
        cout<<"Queue initialized"<<endl;
    }

    bool isEmpty(){
        if(front==nullptr && rear==nullptr)return 1;
        return 0;
    }

    // Function to insert elements into the queue
    void Enqueue(int ele){

        // Create the node to be inserted

        Node * newEle = new Node(ele);


        // If it is the first element front and rear will point to same node
        if(front==nullptr && rear==nullptr){
            front=rear=newEle;
        }
        else{
             // Attach the new node to the queue
            rear->next=newEle;

            // Update the rear pointer
            rear=rear->next;
        }
       

        cout<<"Enqueued element: "<<newEle->data<<" into the queue"<<endl;

    }

    // Function to remove elements from the queue
    void Dequeue(){

        // if the queue is empty
        if(isEmpty()){
            cout<<"Queue underflow: the queue is empty"<<endl;
            return;
        }

        // Get hold of the front node;

        Node * temp=front;
        // store the data present insider the first node
        int data = temp->data;

        //update the front pointer
        front=front->next;

        // if the queue becomes empty
        if(front==nullptr){
            rear=nullptr;
        }

        // delete the first node
        delete temp;

        cout<<"Dequeued element: "<<data<<" from the queue"<<endl;
    }

    // Function to print the elements of the queue
    void print(){

        if(isEmpty()){
            cout<<"Sorry the queue is empty"<<endl;
            return;
        }
        Node * temp=front;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

};


int main(){

    Queue Q1;
    Q1.Enqueue(10);
    Q1.Enqueue(20);
    Q1.Enqueue(30);
    Q1.Enqueue(40);
    Q1.Enqueue(50);
    Q1.print();
    Q1.Dequeue();
    Q1.print();
    Q1.Dequeue();
    Q1.print();
    Q1.Dequeue();
    Q1.print();
    Q1.Dequeue();
    Q1.print();
    Q1.Dequeue();
    Q1.print();
    Q1.print();
    // Q1.print();
    

    return 0;
}