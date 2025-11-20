#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // p[i] will represent: friend i gave a gift to friend p[i]
    vector<int> p(n+1);

    // r[j] will represent: friend j received a gift from friedn r[j]
    vector<int> r(n+1);

    for (int i = 0; i <= n; i++) {
        cin >> p[i];
        int receiver = p[i]; // store the receiver friend number

        // since, i gave a gift to 'receiver',
        // that means 'receiver' received a gift from i
        r[receiver] = i;
    }

    for (int i = 0; i <= n; i++) {
        cout << r[i] << " ";
    }

    cout << "\n";
    return 0;
}