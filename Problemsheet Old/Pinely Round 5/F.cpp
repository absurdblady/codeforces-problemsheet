#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1'000'000'007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) {
        int n; 
        cin >> n;

        if (n <= 1) {
            cout << 0 << '\n';
            for (int i = 0; i < n - 1; ++i) {
                int x, y; cin >> x >> y;
            }
            continue;
        }

        vector<vector<int>> g(n + 1);
        for (int i = 0; i < n - 1; ++i) {
            int u, v; 
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> parent(n + 1, -1), sz(n + 1, 1), order;
        order.reserve(n);
        stack<int> st; 
        st.push(1); 
        parent[1] = 0;

        while (!st.empty()) {
            int u = st.top(); st.pop();
            order.push_back(u);
            for (int v : g[u])
                if (v != parent[u]) {
                    parent[v] = u;
                    st.push(v);
                }
        }

        for (int i = n - 1; i >= 0; --i) {
            int u = order[i];
            for (int v : g[u])
                if (v != parent[u])
                    sz[u] += sz[v];
        }

        vector<long long> pow2(n + 6);
        pow2[0] = 1;
        for (int i = 1; i <= n + 5; ++i)
            pow2[i] = (pow2[i - 1] * 2) % MOD;

        long long ans = 0;
        for (int u = 2; u <= n; ++u) {
            int a = sz[u], b = n - a;
            long long term = ((pow2[a] - 1 + MOD) % MOD) *
                             ((pow2[b] - 1 + MOD) % MOD) % MOD;
            ans = (ans + term) % MOD;
        }

        cout << ans << '\n';
    }
    return 0;
}
