#include<iostream>
#include<vector>
using namespace std;


/* In insertion sort we devide the array in two parts sorted and unsorted

We assume that the first element is sorted so in the array all the elements starting from second element to right are unsorted
We will pick element one by one from the unsorted array and insert them at their correct position in the sorted part
*/

/* INSERTION SORT PROPERTIES

STABLE ALGORITHM
INPLACE ALGORITHM
ADAPTIVE ALGORITHM 


TIME COMPLEXITY

WORST CASE: O(N^2) When list is sorted in reverse order
Average CASE: O(N^2) sorted in random order
Best CASE: O(N)  Already sorted */ 

void insertionSort(vector<int>&arr){

    int n=arr.size();
    // We will consider that the first element of the array is sorted so we will start from the 1st index
    for(int i=1;i<n;i++){

        int key =arr[i];

        // Now compare this key with the elements present in the sorted part and find it's right place

        int j=i-1;

        // Right shift the elements to find the right place for the key element
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        // Now finally place the key at the right place
        arr[j+1]=key;
    }
}

// Function to print the array

void print(const vector<int>&arr){
    for(int x:arr){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main(){

    
     vector<int>arr={20,10,5,40,30,60,50};

    cout<<"Before sorting: ";
    print(arr);

    insertionSort(arr);
    
    cout<<"After sorting: ";
    print(arr);

    return 0;
}