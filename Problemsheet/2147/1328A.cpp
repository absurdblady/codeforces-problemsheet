#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> final;

    while (n--) {
        long long a,b;
        cin >> a >> b;

        long long ans = (b - a % b) % b;
        final.push_back(ans);
    }

    for (long long x : final) cout << x << "\n";

    return 0;
}