#include<iostream>
using namespace std;


// Heap sort for max heap to get elements in increasing order
void heapify(int *arr,int size,int index){

    int largest = index;

    int leftChild = 2* index;
    int rightChild = 2*index+1;

    if(leftChild<=size && arr[leftChild]>arr[largest]){
        largest = leftChild;
    }

    if(rightChild<=size && arr[rightChild]>arr[largest]){
        largest = rightChild;
    }

    if(largest!=index){
        swap(arr[largest],arr[index]);
        heapify(arr,size,largest);
    }



}

void heapSort(int *arr, int size){

    while(size>1){
        swap(arr[size],arr[1]);
        size--;
        heapify(arr,size,1);
    }
}

int main() {
    // Create an array (1-based indexing, arr[0] is dummy)
    int arr[11] = {-1, 30, 10, 50, 20, 60, 15, 40, 70, 5, 25};
    int size = 10;

    // Step 1: Build Max Heap
    cout << "Original array:\n";
    for (int i = 1; i <= size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n\nBuilding max heap...\n";
    for (int i = size / 2; i >= 1; i--) {
        heapify(arr, size, i);
    }

    cout << "Array after building max heap:\n";
    for (int i = 1; i <= size; i++) {
        cout << arr[i] << " ";
    }

    // Step 2: Perform Heap Sort
    cout << "\n\nPerforming heap sort...\n";
    heapSort(arr, size);

    cout << "Sorted array (ascending order):\n";
    for (int i = 1; i <= size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}
