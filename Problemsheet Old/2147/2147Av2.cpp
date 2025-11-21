#include <iostream>

void solve() {
    long long x, y;
    std::cin >> x >> y;

    for (long long k = 1; k <= 200000; ++k) {
        long long c = (k + 1) / 2; // Number of x-steps
        long long d = k / 2;     // Number of y-steps

        // If there are no y-steps, y must be 0
        if (d == 0 && y != 0) {
            continue;
        }

        long long min_x = c * c;
        long long min_y = d * (d + 1);

        // If the minimum required distance is already greater than the target,
        // no solution with this or any larger 'k' is possible.
        if (x < min_x || y < min_y) {
            std::cout << -1 << '\n';
            return;
        }

        long long sum_min = min_x + min_y;

        // Check if the total "extra" distance is even
        if ((x + y - sum_min) % 2 == 0) {
            long long rem_x = x - min_x;
            long long rem_y = y - min_y;

            // ✅ THIS IS THE CORRECTED LOGIC
            // Check if the remaining distance can be validly distributed.
            bool possible = false;
            if (k % 2 != 0) { // k is odd
                if (rem_x >= rem_y) {
                    possible = true;
                }
            } else { // k is even
                if (rem_y >= rem_x) {
                    possible = true;
                }
            }

            if (possible) {
                std::cout << k << '\n';
                return;
            }
        }
    }
    // Fallback for cases where no k in the loop works
    std::cout << -1 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}