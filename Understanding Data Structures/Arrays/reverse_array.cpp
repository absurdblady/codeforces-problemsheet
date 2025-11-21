#include <iostream>
using namespace std;

void reverseArray (int arr[], int n) {

    int s = 0;
    int e = n - 1;

    while (s < e) {
        // loop is running N/2 times, and is proportional to the number of elements
        // O(N)
        swap(arr[s], arr[e]);
        s += 1;
        e -= 1;
    }
}

int main () {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(arr)/sizeof(int);
    
    // print the output
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    reverseArray(arr, n);

    // print the output
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    cout << endl;


    return 0;
}