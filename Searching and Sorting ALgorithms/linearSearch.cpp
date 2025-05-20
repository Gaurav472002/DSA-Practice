#include<iostream>
#include<vector>
using namespace std;


/* The linear search algorithm is a simple search algorithm that checks
 each element in the list one by one until the desired element is found or the end of the list is reached. */

// The best case time complexity of linear search is O(1) when the element is found at the first position.
// The worst case time complexity is O(n) when the element is not present in the list or is at the last position.
// The average case time complexity is O(n) as well, since on average, half of the elements will be checked.
// Linear search is best suited for small lists or unsorted lists where the overhead of more complex algorithms is not justified.
// The space complexity of linear search is O(1) as it does not require any additional data structures or memory allocation.


int linearSearch(vector<int>arr, int key){

    int n=arr.size();

    for(int i=0;i<n;i++){
        if(arr[i]==key){
            cout<<"ELEMENT FOUND AT INDEX: "<<i<<endl;
            return i;
        }
    }
    cout<<"ELEMENT NOT FOUND"<<endl;
    // If the element is not found, return -1
    return -1;
}

int main(){

    vector<int>arr1 ={20,10,30,40,50,60,70,80,90,100};
    int key=30;
    cout<<"ARRAY: ";
    for(int i=0;i<arr1.size();i++){
        cout<<arr1[i]<<" ";
    }   
    

    int res = linearSearch(arr1,key);
    int res2= linearSearch(arr1,33);

    

    return 0;
}