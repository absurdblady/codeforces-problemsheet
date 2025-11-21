#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCount;
    cin >> testCount;

    while (testCount--) {
        int stringLength;
        cin >> stringLength;

        string firstString, secondString;
        cin >> firstString >> secondString;

        sort(firstString.begin(), firstString.end());
        sort(secondString.begin(), secondString.end());

        if (firstString == secondString) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
