#include <bits/stdc++.h>
using namespace std;

struct DisjointSet {
    int size;
    vector<int> parent, bit;

    DisjointSet(int n = 0) {
        init(n);
    }

    void init(int n) {
        size = n;
        parent.assign(size+1,0);
        bit.assign(size+1,0);
        for(int i=0;i<=size;i++){
            parent[i] = i;
            bit[i] = 0;
        }
    }

    int findRoot(int x) {
        if(parent[x] == x) return x;
        int oldParent = parent[x];
        parent[x] = findRoot(parent[x]);
        bit[x] ^= bit[oldParent];
        return parent[x];
    }

    bool connect(int a, int b, int value) {
        int ra = findRoot(a);
        int rb = findRoot(b);
        if(ra == rb) {
            return ((bit[a] ^ bit[b]) == value);
        }
        parent[ra] = rb;
        bit[ra] = bit[a] ^ bit[b] ^ value;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if(!(cin >> t)) {
        return 0;
    }

    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        DisjointSet dsu(n);
        bool possible = true;

        for(int pos=1; pos<=n && possible; pos++) {
            if(s[pos-1] != '1') continue;

            bool hasLeftZero = false;
            bool hasRightZero = false;

            if(pos-1 >= 1 && s[pos-2] == '0') {
                hasLeftZero = true;
            }
            if(pos+1 <= n && s[pos] == '0') {
                hasRightZero = true;
            }

            if(hasLeftZero && hasRightZero) {
                possible = dsu.connect(pos-1, pos+1, 1);
            } else if(hasLeftZero) {
                possible = dsu.connect(pos-1, 0, 0);
            } else if(hasRightZero) {
                possible = dsu.connect(pos+1, 0, 1);
            }
        }

        if(possible) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
