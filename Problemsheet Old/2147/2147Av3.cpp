#include <iostream>
#include <cmath>
#include <algorithm>

// This function correctly checks if 'k' steps can reach (x, y).
bool can_reach(long long k, long long x, long long y) {
    if (k <= 0) {
        return false;
    }
    
    long long c = (k + 1) / 2; // Number of x-steps
    long long d = k / 2;       // Number of y-steps

    // Since y >= 1, k=1 is never possible as it requires y=0.
    if (d == 0) {
        return false;
    }
    
    // Calculate minimum possible x and y for k steps
    long long min_x = c * c;
    long long min_y = d * (d + 1);

    // The target must be reachable
    if (x < min_x || y < min_y) {
        return false;
    }
    
    long long rem_x = x - min_x;
    long long rem_y = y - min_y;

    // Check the remainder distribution condition
    if (k % 2 == 0) { // k is even
        return rem_y >= rem_x;
    } else { // k is odd
        return rem_x >= rem_y;
    }
}

void solve() {
    long long x, y;
    std::cin >> x >> y;

    // Estimate a starting point for k to avoid a long linear search.
    long long k_est = 0;
    if (x > 0 || y > 0) {
        double s = static_cast<double>(x) + y;
        // Solve k(k+1)/2 ≈ s  => k ≈ sqrt(2s)
        k_est = static_cast<long long>((-1.0 + sqrt(1.0 + 8.0 * s)) / 2.0);
    }

    // The answer is very close to our estimate.
    // Search in a small window starting just before the estimate to find the minimum k.
    for (long long k = std::max(1LL, k_est - 2); k < k_est + 5; ++k) {
        if (can_reach(k, x, y)) {
            std::cout << k << '\n';
            return;
        }
    }
    
    // If no solution is found, it's impossible.
    std::cout << -1 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin::tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}