#include <bits/stdc++.h>
using namespace std;

// D. Locked Out — minimal removals = maximum number of pairs (i<j) with a[j]=a[i]+1,
// i.e., maximum matching between values x-1 (left) and x (right) in index order.
// Greedy scan: when we see x, if there's an unmatched (x-1) before, match it.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; 
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        // values are 1..n as per statement
        vector<int> avail(n + 2, 0); // avail[v] = unmatched count of value v seen so far
        long long matching = 0;

        for (int x : a) {
            if (x > 1 && avail[x - 1] > 0) {
                // match an earlier (x-1) with this x
                --avail[x - 1];
                ++matching;
            } else {
                // keep this x available to match with a future (x+1)
                ++avail[x];
            }
        }

        // minimal removals = size of maximum matching
        cout << matching << '\n';
    }
    return 0;
}
