#include <iostream>
using namespace std;

void printAllPairs (int arr[], int n) {

    // printing elements
    // used 2 nested loops
    // didn't print the pairs of same elements
    
    for (int i = 0; i < n; i++) {
        int x = arr[i];

        for (int j = 0; j < n; j++) {
            int y = arr[j];
            
            if (x != y) {
                cout << x << "," << y << endl;
            }
            
        }

        cout << endl;
    }
}

int main () {
    int arr[] = {10, 20, 30, 40};
    int n = sizeof(arr)/sizeof(int);
    
    printAllPairs(arr, n);

    return 0;
}