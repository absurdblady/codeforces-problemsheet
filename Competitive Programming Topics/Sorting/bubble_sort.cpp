#include <bits/stdc++.h>
using namespace std;

int main() {
    int array[] = {1,4,5,3,2,9,8};
    int n = sizeof(array)/sizeof(int);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            if (array[j] > array[j+1]) {
                swap(array[j],array[j+1]);
                for (int k = 0; k < n; k++) {
                    cout << array[k] << " ";
                }
                cout << endl;
            }
        }
    }
}

