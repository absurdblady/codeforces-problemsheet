#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    string magnet, prev;
    int groups = 0;

    for (int i=0; i<n; i++) {
        cin >> magnet;

        if (int i=0 || magnet!=prev) {
            groups++;
        }
        prev = magnet;
    }

    cout << groups << endl;
    return 0;
}