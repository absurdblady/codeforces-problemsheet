#include <bits/stdc++.h>
using namespace std;

long long compute_blocks(int n, vector<int>& p, vector<int>& s) {
    vector<int> posP(n+1), posS(n+1);
    for (int i = 0; i < n; i++) {
        posP[p[i]] = i;
        posS[s[i]] = i;
    }
    long long ans = 0;
    int cur = 1;
    while (cur <= n) {
        int L = cur, R = cur;
        int maxP = posP[cur], maxS = posS[cur];
        int bound = max(maxP, maxS);
        while (cur <= n && cur - L <= bound - L) {
            bound = max({bound, posP[cur], posS[cur]});
            cur++;
        }
        int len = cur - L;
        ans += 1LL * len * len;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<int> p(n), s(n);
        for (int i = 0; i < n; i++) cin >> p[i];
        for (int i = 0; i < n; i++) cin >> s[i];
        while (q--) {
            int tp, u, v;
            cin >> tp >> u >> v;
            --u; --v;
            if (tp == 1) swap(p[u], p[v]);
            else swap(s[u], s[v]);
            cout << compute_blocks(n, p, s) << "\n";
        }
    }
}
