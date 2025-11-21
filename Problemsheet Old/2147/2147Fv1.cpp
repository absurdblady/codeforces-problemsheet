#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, sz;
    long long total;
    DSU(int n) {
        parent.resize(n+1);
        sz.assign(n+1,1);
        iota(parent.begin(), parent.end(), 0);
        total = n; // initially n*1*1
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a,b);
        total -= 1LL*sz[a]*sz[a] + 1LL*sz[b]*sz[b];
        sz[a] += sz[b];
        parent[b] = a;
        total += 1LL*sz[a]*sz[a];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<int> p(n), s(n);
        for (int i=0;i<n;i++) cin >> p[i];
        for (int i=0;i<n;i++) cin >> s[i];

        DSU dsu(n);

        auto add_edges = [&](vector<int>& arr) {
            for (int i=1;i<n;i++) {
                dsu.unite(arr[i], arr[i-1]);
            }
        };
        add_edges(p);
        add_edges(s);

        while (q--) {
            int t,u,v;
            cin >> t >> u >> v;
            --u; --v;
            if (t==1) swap(p[u], p[v]);
            else swap(s[u], s[v]);

            // Only need to recheck adjacency near swapped indices
            auto recheck = [&](vector<int>& arr, int idx) {
                if (idx > 0) dsu.unite(arr[idx], arr[idx-1]);
                if (idx+1 < n) dsu.unite(arr[idx], arr[idx+1]);
            };
            recheck(t==1 ? p : s, u);
            recheck(t==1 ? p : s, v);

            cout << dsu.total << "\n";
        }
    }
}
