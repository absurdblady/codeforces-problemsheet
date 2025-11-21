#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    // array of 26 booleans, all false at start
    vector<bool> seen(26, false);

    // mark each letter
    for (char c : s) {
        if (c >= 'a' && c <= 'z') {
            seen[c - 'a'] = true;
        } else if (c >= 'A' && c <= 'Z') {
            seen[c - 'A'] = true;   // handle uppercase too
        }
    }

    // check if all letters were seen
    for (bool v : seen) {
        if (!v) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}
