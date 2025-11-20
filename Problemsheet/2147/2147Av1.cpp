#include <iostream>
using namespace std;

void solve() {
    long long x, y;
    cin >> x >> y;

    for (long long k = 1; k <= 200000; ++k) {
        long long c = (k + 1) / 2; // Number of x-steps
        long long d = k / 2;       // Number of y-steps

        if (d == 0 && y != 0) continue;

        long long min_x = c * c;
        long long min_y = d * (d + 1);

        if (x < min_x || y < min_y) continue;

        long long sum_min = min_x + min_y;

        if ((x + y - sum_min) % 2 == 0) {
            long long rem_x = x - min_x;
            long long rem_y = y - min_y;

            // ✅ Only need non-negative remainders
            if (rem_x >= 0 && rem_y >= 0) {
                cout << k << '\n';
                return;
            }
        }
    }
    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
