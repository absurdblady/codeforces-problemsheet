#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string hate = "I hate";
    string love = "I love";



    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            cout << hate;
        } else {
            cout << love;
        }

        if (i != n) cout << " that ";
    }

    cout << " it";
    return 0;

    // what i learnt here is kind of revision
    // once the first if condition passes with either if or else, then the next if condition runs
}