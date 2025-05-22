#include<iostream>
using namespace std;


class Deque{

    int * arr;
    int front;
    int rear;
    int size;

    public:

    Deque(int size){
        this->size=size;
        front=rear=-1;
        arr= new int[size];

        cout<<"Deque of size: "<<size<<" initialized"<<endl;
    }

    ~Deque(){
        delete []arr;
        cout<<"Memory of deque freed"<<endl;
    }

    // function to check if the deque is full

    bool isFull(){
        return (rear+1)%size==front;
    }

    // Function to check if the deque is empty
    bool isEmpty(){
        return front==-1;
    }

    // Function to insert element using the rear end
    void pushRear(int ele){

        if(isFull()){
            cout<<"Deque overflow"<<endl;
            return;
        }
        if(isEmpty()){
            front=rear=0;
        }
        else{
            rear=(rear+1)%size;
        }
        arr[rear]=ele;
        
        cout<<"Inserted element: "<<ele<<" from the rear end"<<endl;
    }
    
    // Function to insert element using the front end
    void pushFront(int ele){

        if(isFull()){
            cout<<"Deque overflow"<<endl;
            return;
        }
        if(isEmpty()){
            front=rear=0;
        }
        else if( front==0){
            front=size-1;
        }
        else{
            front--;
        }
        arr[front]=ele;
        cout<<"Inserted element: "<<ele<<" from the front end"<<endl;

    }

    // Function to delete element from the front end
    void popFront(){

        if(isEmpty()){
            cout<<"Deque underflow"<<endl;
            return;
        }

        int ele=arr[front];

        if(front==rear){
            front=rear=-1;
        }
        else{
            front=(front+1)%size;
        }

        cout<<"Deleted element: "<<ele<<" from the front end"<<endl;
    }

    // Function to delete element from the rear end
    void popRear(){

        if(isEmpty()){
            cout<<"Deque underflow"<<endl;
            return;
        }

        int ele=arr[rear];

        if(front==rear){
            front=rear=-1;
        }
        else if(rear==0){
            rear=size-1;
        }
        else{
            rear--;
        }

        cout<<"Deleted element: "<<ele<<" from the rear end"<<endl;
    }

    // Function to print the element of the deque
    void print(){

        if(isEmpty()){
            cout<<"deque is empty"<<endl;
            return;
        }

        int i=front;

        while(true){
            cout<<arr[i]<<" ";
            if(i==rear){
                break;
            }
            i=(i+1)%size;
        }
        cout<<endl;
    }
};

int main() {
    Deque dq1(5);

    dq1.pushRear(10);
    dq1.pushRear(20);
    dq1.pushRear(30);
    dq1.print();  // Output: 10 20 30

    dq1.pushFront(5);
    dq1.print();  // Output: 5 10 20 30

    dq1.pushFront(1);
    dq1.print();  // Output: 1 5 10 20 30

    // Trying to push when full
    dq1.pushRear(99);  // Should show overflow

    dq1.popFront();
    dq1.print();  // Output: 5 10 20 30

    dq1.popRear();
    dq1.print();  // Output: 5 10 20

    dq1.pushRear(40);
    dq1.pushFront(2);
    dq1.print();  // Output: 2 5 10 20 40

    // Pop all to test empty condition
    dq1.popFront();
    dq1.popFront();
    dq1.popFront();
    dq1.popFront();
    dq1.popFront();
    dq1.print();  // Should say deque is empty

    dq1.popRear();  // Underflow
    dq1.popFront(); // Underflow

    return 0;
}
