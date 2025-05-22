#include<iostream>
using namespace std;


class Array{

    // Pointer to store the array
    int *arr;
    // Represents the current number of elements in the array
    int size;
    // Represents the total capacity of the array
    int capacity;

    public:
    Array(int capacity){
        this->capacity=capacity;
        
        // initialize the array
        arr= new int[capacity];
        size=0;

        cout<<"Array of size: "<<capacity<<" initialized"<<endl;
    }

    ~Array(){
        delete []arr;

        cout<<"Memory of array freed"<<endl;
    }


    // Function to check if the array is full or not
    bool isFull(){
        return size==capacity;
    }

    // Function to check if the array is empty or not
    bool isEmpty(){
        return size==0;
    }

    // Function to insert an element at the beginning of the array
    void insertAtFirst(int ele){
        if(isFull()){
            cout<<"Sorry the array is full"<<endl;
            return;
        }
        

        for(int i=size;i>0;i--){
            arr[i]=arr[i-1];
        }
        arr[0]=ele;
        // increase the size
        size++;
        cout<<"Inserted element: "<<ele<<" at the first position"<<endl;
    }

    // Function to insert an element at the end of the array
    void insertAtEnd(int ele){
        if(isFull()){
            cout<<"Sorry the array is full"<<endl;
            return;
        }

        // place the element at the end
        arr[size]=ele;
        size++;

        cout<<" Inserted element: "<<ele<<" at the end"<<endl;
    }

    // function to insert element at specific position

    void insertAtPosition(int ele,int pos){
        if(pos<0 || pos>capacity-1){
            cout<<"Please enter a valid position"<<endl;
            return;
        }

        // first check if there is space in the array

        if(isFull())return;

        if(pos==0){
            insertAtFirst(ele);
            return;
        }
        else if(pos==size){
            insertAtEnd(ele);
            return;
        }
        else{

            
            // right shift all the elements up to the position
            
            for(int i=size;i>=pos;i--){
                arr[i]=arr[i-1];
            }
            arr[pos]=ele;
            cout<<"Inserted element: "<<ele<<" at position: "<<pos<<endl; 
            // increment the size
            size++;
        }
    }


    // Function to delete the first element of the array

    void deleteFirst(){

        if(isEmpty()){
            cout<<"Sorry the array is empty"<<endl;
            return;
        }

        // Store the element
        int ele =arr[0];

        // now left shift all the elements
        for(int i=0;i<size;i++){
            arr[i]=arr[i+1];
        }
        // decrement the size
        size--;

        cout<<"Deleted element: "<<ele<<" from the array"<<endl;
    }

    // Function to delete the last element of the array

    void deleteLast(){
        if(isEmpty()){
            cout<<"Sorry the array is empty"<<endl;
            return;
        }

        // store the element
        int ele =arr[size-1];

        // reduce the size of the array

        size--;

        cout<<"Deleted element: "<<ele<<" from the array"<<endl;
    }

    // Function to delete a specific element from the array

    void deleteELement(int ele){
        // if it is the first element
        if(ele==arr[0]){
            deleteFirst();
            return;
        }
        // if its' the last element
        else if(ele==arr[size-1]){
            deleteLast();
            return;
        }
        // Find the element and delete it
        else{

            bool found=false;
            for(int i=1;i<size-1;i++){
                if(arr[i]==ele){
                    
                    found=1;
                    // left shift the next elements
                    for(int j=i;j<size;j++){
                        arr[j]=arr[j+1];
                    }
                    // decrement the size
                    size--;
                    break;

                }
            }
            if(found==false){
                cout<<"Element not found in the array"<<endl;
            }
            else{
                cout<<"Deleted element: "<<ele<<" from the array"<<endl;
            }

        }
    }


    // Function to print the elements of the arrays
    void print(){
        cout<<"Array elements: ";
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    

};

int main(){

    Array a1(5);

    a1.insertAtFirst(10);
    a1.insertAtEnd(20);
    a1.insertAtEnd(30);
    a1.insertAtEnd(40);
    a1.insertAtEnd(50);
    a1.insertAtEnd(1);
    a1.print();
    a1.deleteLast();
    a1.insertAtEnd(22);
    a1.print();
    a1.deleteFirst();
    a1.print();
    a1.insertAtFirst(55);
    a1.print();

    a1.deleteELement(30);
    a1.print();

    a1.insertAtPosition(222,3);
    a1.print();

    return 0;
}