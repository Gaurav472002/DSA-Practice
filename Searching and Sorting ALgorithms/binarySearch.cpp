#include <iostream>
#include <vector>
using namespace std;

// The binary search algorithm is a more efficient search algorithm that works on sorted lists.
// It divides the list into two halves and checks if the desired element is in the left or right half.
// The process is repeated until the element is found or the search space is empty.

// The best case time complexity of binary search is O(1) when the element is found at the middle position.
// The worst case time complexity is O(log n) when the element is not present in the list.
// The average case time complexity is O(log n) as well, since the search space is halved with each iteration.
// The space complexity of binary search is O(1) as it does not require any additional data structures or memory allocation.
// If the stack space used by the recursive calls is considered, the space complexity would be O(log n) for the recursive version.

int binarySearch(vector<int> arr, int key)
{

    int n = arr.size();

    int low = 0;
    int high = n - 1;

    while (low <= high)
    {

        /* why low+(high-low)/2 instead of low+high/2 because low+high can result to integer overflow */
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
        {
            cout << " Key found at index: " << mid << endl;
            return mid;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << "Key not found in the array" << endl;
    return -1;
}

int recursiveBinarySearch(int low, int high, vector<int> &arr, int key)
{

    if (high >= low)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {

            cout << "Key found at index: " << mid << endl;
            return mid;
        }
        else if (arr[mid] < key)
        {
            return recursiveBinarySearch(mid + 1, high, arr, key);
        }
        else
        {
            return recursiveBinarySearch(low, mid - 1, arr, key);
        }
    }

    return -1;
}

int main()
{

    vector<int> arr1 = {10, 20, 30, 40, 50};
    int n = arr1.size();
    int res1 = binarySearch(arr1, 20);
    int res2 = binarySearch(arr1, 1);

    int res3 = recursiveBinarySearch(0, n - 1, arr1, 110);
    cout << res3;

    return 0;
}