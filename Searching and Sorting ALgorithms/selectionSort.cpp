#include<iostream>
#include<vector>
using namespace std;

/* SELECTION SORT PROPERTIES

NOT STABLE ALGORITHM
INPLACE ALGORITHM
NOT ADAPTIVE ALGORITHM 


TIME COMPLEXITY

WORST CASE: O(N^2)
Average CASE: O(N^2)
Best CASE: O(N ^2) 

Selection Sort was designed to optimize the number of swaps compared to Bubble Sort, which swaps too frequently.

*/


void selectionSort(vector<int>&arr){

    int n=arr.size();
    // Declare the number of passes
    // We do n-1 instead of n because the last element will be automatically at it's right place because n-1 elements are already placed according to their correct position
    for(int i=0;i<n-1;i++){

        // Select the minimum element for this particular index
        int minIndex=i;

        for(int j=i+1;j<n;j++){
            // Find the element which is smaller than the current minElement index
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        // Swap the values if the minimumIndex is updated
        if(minIndex!=i){
            swap(arr[minIndex],arr[i]);
        }
    }

}


// Function to print the array
    void print(vector<int>arr){
        for(int x:arr){
            cout<<x<<" ";
        }
        cout<<endl;
    }

int main(){


    vector<int>arr={20,10,5,40,30,60,50};

    cout<<"Before sorting: ";
    print(arr);

    selectionSort(arr);
    
    cout<<"After sorting: ";
    print(arr);

    return 0;
}