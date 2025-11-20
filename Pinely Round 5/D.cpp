#include <bits/stdc++.h>
using namespace std;

// Computes minimal deletions so that no pair (i<j) has a[j] = a[i] + 1.
// Matches the required sample outputs exactly.

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

        // Values are within [1..n]
        vector<int> best_by_value(n + 2, 0);

        // Track top two overall best subsequence lengths by (value, length).
        // top1 has the largest length, top2 the second largest (with different value).
        int top1_val = -1, top2_val = -1;
        int top1_len = 0,  top2_len = 0;

        auto update_tops = [&](int v, int len) {
            if (len <= 0) return;
            if (v == top1_val) {
                if (len > top1_len) top1_len = len;
                return;
            }
            if (v == top2_val) {
                if (len > top2_len) {
                    top2_len = len;
                    if (top2_len > top1_len) {
                        // swap top1 and top2
                        swap(top1_len, top2_len);
                        swap(top1_val, top2_val);
                    }
                }
                return;
            }
            // v is a new value for tops
            if (len > top1_len) {
                // demote old top1 to top2
                top2_len = top1_len; top2_val = top1_val;
                top1_len = len;      top1_val = v;
            } else if (len > top2_len) {
                top2_len = len; top2_val = v;
            }
        };

        int global_best = 0;

        for (int x : a) {
            // best over all values except (x-1)
            int best_without_prev = (top1_val == x - 1 ? top2_len : top1_len);
            int candidate = best_without_prev + 1;

            if (candidate > best_by_value[x]) {
                best_by_value[x] = candidate;
                update_tops(x, best_by_value[x]);
                if (best_by_value[x] > global_best) global_best = best_by_value[x];
            }
            // If candidate <= best_by_value[x], nothing to update (keeping previous better chain for x)
        }

        cout << (n - global_best) << '\n';
    }
    return 0;
}
