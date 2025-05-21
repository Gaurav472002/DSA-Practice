#include<iostream>
#include<vector>
using namespace std;

/*Quicksort is called quick because it's generally faster than other sorting algorithms,
 particularly when dealing with larger datasets*/

/* MERGE SORT PROPERTIES

NOT STABLE ALGORITHM ❌
INPLACE ALGORITHM becaue extra space is used ✅
NOT ADAPTIVE ALGORITHM ❌


TIME COMPLEXITY

Worst CASE: O(N^2)  // Poor pivot choice when the array is divided unevenly
Average CASE: O(N log N) 
Best CASE: O(N log N)   */


int partition(vector<int>&arr,int low,int high){

    // This is called Hoare-style partitioning
    // Let us consider the first element as the pivot element
    int pivot =arr[low];

    // Count how many elements are less than the pivot element

    int count =0;
    for(int i=low+1;i<=high;i++){
        if(arr[i]<=pivot)count++;
    }

    //  Get the pivot index
    int pivot_Index = low+count;
    // Place the pivot element at right place
    swap(arr[low],arr[pivot_Index]);

    // Now we will make sure all the elements to the left of pivot are smaller and righter elements are larger

    int i=low;
    int j=high;

    while(i<pivot_Index && j>pivot_Index){
        while(arr[i]<=pivot)i++;
        while(arr[j]>pivot)j--;
        if(i<pivot_Index && j>pivot_Index){
            swap(arr[i++],arr[j--]);
        }
    }
    // return the pivot index
    return pivot_Index;
}


void quickSort(vector<int>&arr,int low,int high){

    // If only a single element is left return
    if(low>=high)return;

    // Find the pivot index using partition algorithm
    int pivot_Index= partition(arr,low,high);

    // now sort the left half of the pivot element;
    quickSort(arr,low,pivot_Index-1);
    
    // Sort the right half of the pivot element

    quickSort(arr,pivot_Index+1,high);
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

    int n=arr.size();

    int low=0;
    int high=n-1;

    cout<<"Before sorting: ";
    print(arr);

    quickSort(arr,low,high);
    
    cout<<"After sorting: ";
    print(arr);
}