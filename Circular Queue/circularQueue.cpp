#include <iostream>
using namespace std;

class CircularQueue
{

    int *arr;
    int size;
    int front;
    int rear;

public:
    CircularQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
        cout << "Circular queue of size: " << size << " initialized" << endl;
    }

    ~CircularQueue()
    {
        delete[] arr;
        cout << "Memory freed" << endl;
    }

    bool isFull()
    {
        return (rear + 1) % size == front;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    void enqueue(int ele)
    {
        if (isFull())
        {
            cout << "Queue overflow" << endl;
            return;
        }
        if (rear == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }
        arr[rear] = ele;

        cout << "Enqueued element: " << ele << " into the queue" << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Sorry the queue is empty" << endl;
            return;
        }

        // s
        int ele = arr[front];

        // if only 1 element left then reset the pointers
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
        cout << "Dequeued element: " << ele << " from the queue" << endl;
        return;
    }

    // function to print the elements of the circular queue
    void print()
    {

        if (isEmpty())
        {
            cout << "the circular queue is empty " << endl;
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (true)
        {
            cout << arr[i] << " "; // Print current element

            if (i == rear)
                break; // Stop if we've reached the rear

            i = (i + 1) % size; // Move to next index circularly
        }
        cout << endl;
    }
};

int main()
{

    CircularQueue q1(5);

    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    q1.dequeue();
    q1.enqueue(200);
    q1.dequeue();
    q1.print();

    return 0;
}