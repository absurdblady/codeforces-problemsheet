#include <iostream>
using namespace std;

int main() {
    int n, opinion;
    cin >> n;
    bool found_hard = false;

    for (int i = 0; i < n; ++i) {
        cin >> opinion;
        if (opinion == 1) {
            found_hard = true;
        }
    }

    if (found_hard) {
        cout << "HARD" << endl;
    } else {
        cout << "EASY" << endl;
    }

    return 0;
}