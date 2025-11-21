#include <iostream>
using namespace std;

int main() {
    int marks[10];

    int n;
    cout << "enter the number of students : ";
    cin >> n;

    // assign a value
    marks[0] = -1;

    // input
    for(int i = 0; i < n; i++) {
        cin >> marks[i];

        // update
        marks[i] = marks[i] * 2
    }

    // output
    for(int i = 0; i < n; i++) {
        cout << marks[i] << " ,";
    }

    cout << endl;
    return 0;
}