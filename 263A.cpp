#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int value, row, col;

    for (int i=1; i<=5; i++) {
        for (int j=1; j<=5; j++) {
            cin >> value;
            if (value == 1) {
                row = i;
                col = j;
            }
        } 
    }

    int moves  = abs(row - 3) + abs(col - 3);
    cout << moves << endl;

    return 0;
}