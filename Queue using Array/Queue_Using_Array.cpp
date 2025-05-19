#include<iostream>
using namespace std;


class Queue{


    int *arr;
    int front;
    int rear;
    int size;

    public:

    // Constructor for Queue
    Queue(int size){
        this->size=size;
        this->front=-1;
        this->rear=-1;
        arr= new int[size];
        cout<<"Queue of size: "<<size<<" initialized"<<endl;
    }

    // Destructor to free the memory of the queue

    ~Queue(){
        delete []arr;
        cout<<"Memory freed"<<endl;
    }

    // Function to check if the queue is empty or not
    int isEmpty(){
        if(front==-1 && rear==-1)return 1;
        return 0;
    }

    // Function to check if the queue is full or not
    int isFull(){

        return rear==size-1;
    }

    // Function to insert elements into the queue
    void Enqueue(int ele){
        // cout<<"here";
        if(isFull()){
            cout<<"Queue Overflow"<<endl;
            return ;
        }
        
        // Case when we enter the first element in the queue

        if(isEmpty()){
            front=0;
            rear=0;
        }
        else{   
            rear++;
        }
        
        arr[rear]=ele;

        cout<<"Enqueued element: "<<ele<<" into the queue"<<endl;

    }

    // Function to remove element from the queue
    void Dequeue(){

        if(isEmpty()){
            cout<<"Queue Underflow: the stack is empty"<<endl;
            return;
        }

        int ele =arr[front];

        // Update the front pointer

        front++;

        // reset the pointer if the queue is empty
        if(front>rear){
            front=-1;
            rear=-1;
        }

        cout<<"Dequeued element: "<<ele<<" from the queue"<<endl;
    }

    // Function to print the elements of the queue
    void print(){

        if(isEmpty()){
            cout<<"Can't print the elements the queue is empty"<<endl;
            return;
        }

        for(int i=front;i<=rear;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};

int main(){

    Queue Q1(5);

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
    return 0;
}