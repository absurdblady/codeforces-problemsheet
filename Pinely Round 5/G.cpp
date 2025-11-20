#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    const int MAXB = 20;
    vector<int> nxt(1 << MAXB, 0);
    for (int i = (1 << MAXB) - 2; i >= 0; --i)
        nxt[i] = ((i + 1) & i) == i ? nxt[i + 1] + 1 : 0;

    while (q--) {
        int X;
        cin >> X;
        int ans = INT_MAX;

        for (int mask = X; mask < (1 << MAXB); mask = (mask + 1) | X) {
            int cur = 0;
            for (int ai : a)
                cur += ((mask & (~ai)) & -((mask & (~ai)))); // smallest addition for ai→mask
            if ((mask & ~X) == 0)
                ans = min(ans, cur);
        }
        cout << ans << '\n';
    }
}
