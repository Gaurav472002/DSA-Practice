#include<iostream>
#include<vector>
using namespace std;


/* BUBBLE SORT PROPERTIES

STABLE ALGORITHM
INPLACE ALGORITHM
ADAPTIVE ALGORITHM - using flag variable


TIME COMPLEXITY

WORST CASE: O(N^2)
Average CASE: O(N^2)
Best CASE: O(N) using flag vairable

*/

void bubbleSort(vector<int>&arr){

    int n=arr.size();

    // Declare the number of passes
    // Why n-1 because if we n-1 elements are at the right place then the nth element will be at right place as well
    // After every pass the biggest element find's it's right place
    for(int i=0;i<n-1;i++){

        // Number of comparisons they will reduce after every pass
        bool flag =false;
        for(int j=0;j<n-i-1;j++){
            
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag=true;
            }
            
        }
        if(flag==false)break;
    }
}

// Function to print the elements of the array
void print(vector<int>arr){
    for(int x:arr){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main(){

    vector<int>arr1={20,50,10,30,40};
    cout<<"Before sorting: ";
    print(arr1);
    bubbleSort(arr1);
    cout<<"After sorting: ";
    print(arr1);

    return 0;
}