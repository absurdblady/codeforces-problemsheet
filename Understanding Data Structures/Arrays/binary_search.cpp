// binary search is an efficient searching algorithm to find the index of element in a sorted array
/*
s = 0, e = n-1
while (s <= e) {
    find mid
    do comparison at mid
        equal = return mid
        > left or
        < right
}
*/

#include <iostream>
using namespace std;

int binary_search (int arr[], int n, int key) {
    // implement binary search
    int s = 0;
    int e = n - 1;

    while (s <= e) {
        // time complexity : for k iterations, N/2^k will be 1
        // so N = 2^k, k = lg(N), O(logN) 
        // fast and efficient, works only if the search space is sorted or monotonic
        // values should be non-decreasiong or non increasing
        int mid = (s+e)/2;

        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] > key) {
            e = mid - 1;
        } 
        else {
            s = mid + 1;
        }
    }
    return -1;
}

int main () {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(arr)/sizeof(int);

    int key;
    cin >> key;

    int index = binary_search(arr, n, key);
    if (index != -1) {
        cout << key << " is present at index " << index << endl;
    }
    else {
        cout << key << " is NOT Found!" << endl;
    }
}