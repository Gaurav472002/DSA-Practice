#include<iostream>
#include<vector>
using namespace std;


/* The main Idea of the merge sort is to divide the array into two parts sort the two parts and then merge them back

In merge sort, you're recursively sorting parts of the array. So merge() is only responsible for sorting the portion 
from index low to high.

🔁 If you used mainIndex = 0:
You would accidentally overwrite elements at the start of the array, even if you're only trying to sort a middle segment 
(like indices 3 to 6). This would corrupt your data.
*/

/* MERGE SORT PROPERTIES

STABLE ALGORITHM ✅
Not INPLACE ALGORITHM becaue extra space is used ❌
NOT ADAPTIVE ALGORITHM ❌


TIME COMPLEXITY

Worst CASE: O(N log N) 
Average CASE: O(N log N) 
Best CASE: O(N log N)   */


// Helper function to merge the two halfs of the array
void merge(vector<int>&arr,int low,int high,int mid){


    // Find the length of the first half
    int len1= mid-low+1;
    // Find the length of the second half;
    int len2 = high-mid;

    // Base case if two elements are present and both are sorted
    if(len1==1 && len2==1 && arr[low]<arr[high])return;

    // create two new arrays to store the elemetns from both half

    vector<int>arr1(len1);
    vector<int>arr2(len2);

    int index1=0;
    int index2=0;

    int mainIndex=low;

    // copy the first half
    for(int i=0;i<len1;i++){
        arr1[i]=arr[mainIndex++];
    }

    // copy the second half
    for(int i=0;i<len2;i++){
        arr2[i]=arr[mainIndex++];
    }

    // Reset the pointer for the main array
    mainIndex=low;
    // Now sort the main array using the sorted elements from both the array
    while(index1<len1 && index2<len2){
        if(arr1[index1]<arr2[index2]){
            arr[mainIndex++]=arr1[index1++];
        }
        else{
            arr[mainIndex++]=arr2[index2++];
        }
    }

    // If the left half is longer

    while(index1<len1){
        arr[mainIndex++]=arr1[index1++];
    }

    // If the right half is longer

    while(index2<len2){
        arr[mainIndex++]=arr2[index2++];
    }

    // delete the extra two vectors
    arr1.clear();
    arr2.clear();
}

// Function to sort the array using the merge sort
void mergeSort(vector<int>&arr,int low,int high){

    // Overflow condition
    if(low>=high)return;

    // Find the mid of the array;
    int mid = low+(high-low)/2;

    // Sort the first left half
    mergeSort(arr,low,mid);
    // Sort the next right half
    mergeSort(arr,mid+1,high);

    // Now merge both of the halfs to sort the whole array

    merge(arr,low,high,mid);

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

    int n=arr.size();
    int low=0;
    int high =n-1;


    cout<<"Before sorting: ";
    print(arr);

    mergeSort(arr,low,high);
    
    cout<<"After sorting: ";
    print(arr);

    return 0;
}