#include <iostream>
using namespace std;

class Heap
{

    int *arr;
    int pos;
    int size;

public:
    Heap(int size)
    {
        this->size = size;
        arr = new int[size + 1];
        pos = 0;
        arr[0] = -1; // Following 1 based indexing
        cout << " Heap Initialized" << endl;
    }

    // destructor for heap
    ~Heap()
    {
        delete[] arr;
    }

    // Function to  insert an element into the heap
    void insert(int x)
    {

        if (pos == size)
        {
            cout << " Sorry the heap is full " << endl;
            return;
        }

        // increment the pointer
        pos++;

        int index = pos;
        // insert the element
        arr[index] = x;

        // now time to find the right place for the newly inserted element in the heap

        while (index > 1)
        {

            int parent = index / 2;

            if (arr[index] < arr[parent])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return; // heap property satisfied
            }
        }
    }

    // Function to delete the minimum element from the heap
    void extractMin()
    {

        if (pos == 0)
        {
            cout << " Sorry the heap is empty" << endl;
            return;
        }

        // replace root with the last element
        // store the element to be deleted

        int x = arr[1];
        arr[1] = arr[pos];
        pos--; // reduce the size of the heap
        int index = 1;

        // now find the right place for the element at the root

        while (index <= pos)
        {

            int leftchild = 2 * index;
            int rightchild = 2 * index + 1;
            int swapIndex = index;

            if (leftchild <= pos && arr[leftchild] < arr[swapIndex])
            {
                swapIndex = leftchild;
            }

            if (rightchild <= pos && arr[rightchild] < arr[swapIndex])
            {
                swapIndex = rightchild;
            }

            // if we found a smaller element then swap it

            if (index != swapIndex)
            {
                swap(arr[index], arr[swapIndex]);
                index = swapIndex;
            }
            else
            {
                return;
            }
        }
        cout << " Removed: " << x << " from the heap" << endl;
    }

    // Function to print the heap

    void print()
    {

        for (int i = 1; i <= pos; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    bool isEmpty()
    {
        return pos == 0;
    }
};

int main()
{
    Heap h(10); // Create a min-heap of size 10

    // Test insertions
    cout << "\nInserting elements into the heap:\n";
    h.insert(50);
    h.insert(30);
    h.insert(40);
    h.insert(10);
    h.insert(20);
    h.insert(60);

    cout << "Heap after insertions: ";
    h.print(); // Expected: min element at root (index 1)

    // Test deletion of root (extractMin)
    cout << "\n\nDeleting root element:\n";
    h.extractMin(); // Remove the smallest element
    cout << "Heap after deleting root: ";
    h.print();

    // Insert more elements
    cout << "\n\nInserting more elements:\n";
    h.insert(15);
    h.insert(5);
    h.insert(70);
    h.insert(25); // Should trigger "Heap is full" if size limit reached

    cout << "Heap after more insertions: ";
    h.print();

    // Try deleting all elements
    cout << "\n\nDeleting all elements:\n";
    while (true)
    {
        h.extractMin();
        h.print();
        cout << endl;
        if (h.isEmpty())
            break;
    }

    return 0;
}
