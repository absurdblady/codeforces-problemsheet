#include <iostream>
using namespace std; 

void printArray(int arr[], int n) {
    cout << "In Function " << sizeof(arr) << endl; // address of the array

    // int n = sizeof(arr)/sizeof(int);
    // we don't have the correct value of n here
    // here pass by reference has happned
    // instead of passing the address, we have passed the address
    // the array is 24 bytes, passing the address to printArray it occupies 8 bytes
    // we can use int * arr instead
    // so pass n from main to printArray

    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
}

int main() {
    int arr[] = {1,2,3,4,5,6}; // 6 x 4 = 24 bytes
    int n = sizeof(arr)/sizeof(int); // 24 bytes / 4 bytes = 6

    cout << "In Main " << sizeof(arr) << endl; // array

    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    printArray(arr, n); 

    return 0;
}