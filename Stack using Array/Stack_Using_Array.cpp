#include <iostream>
using namespace std;

class Stack
{

    int size;
    int *arr;
    int top;

public:
    Stack(int size)
    {
        this->size=size;
        arr=nullptr;
        top=-1;
        arr = new int[size];

        cout << "Stack of size: " << size << " initialized" << endl;
    }
    ~Stack(){
        delete []arr;
        cout<<"Stack memory freed"<<endl;
    }

    // Function to check if the stack is full or not
    int isFull()
    {
        return top == size - 1;
    }

    // Function to check if the stack is empty or not
    int isEmpty()
    {
        return top == -1;
    }

    // Function to push an element into the stack
    int push(int ele)
    {

        // If the stack is full return stack overflow
        if (isFull())
        {
            cout << "Stack overflow" << endl;
            return -1;
        }
        // Increment the top pointer
        top++;
        // Place the element into the stack
        arr[top] = ele;
        cout << "Pushed: " << ele << " successfully to the stack" << endl;

        return ele;
    }

    // Function to remove the topmost element of the stack
    int pop()
    {

        // If the stack is empty return stack underflow
        if (isEmpty())
        {
            cout << "Stack underflow" << endl;
            return -1;
        }

        // Get hold of the topmost element of the stack
        int ele = arr[top];
        // Decrement the top pointer so that it points to the next element of the top
        top--;
        cout << "Popped: " << ele << " from the stack" << endl;
        return ele;
    }

    // Function to peek on to the stack and return the topmost element
    int peek()
    {

        if (isEmpty())
        {
            cout << "Stack is empty " << endl;
            return -1;
        }

        return arr[top];
    }

    // Function to print the stack
    void print()
    {
        if(isEmpty()){
            cout<<"The stack is empty"<<endl;
            return;
        }
        cout << "Stack elements:" << endl;
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << endl;
            ;
        }
    }
};

int main()
{

    Stack S1(5);
    
    S1.push(5);
    S1.push(10);
    S1.push(15);
    cout<<S1.peek();
    S1.push(20);
    S1.push(51);
    S1.push(100);
    S1.print();
    S1.pop();
    S1.pop();
    S1.pop();
    S1.pop();
    S1.pop();
    S1.pop();
    S1.print();

    return 0;
}