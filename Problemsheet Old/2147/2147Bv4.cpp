#include <iostream>
#include <vector>
#include <numeric>
#include <set>

// Fast I/O
void fast_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
}

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n;

    // Use a set to keep track of available 1-based indices
    std::set<int> available_indices;
    for (int i = 1; i <= 2 * n; ++i) {
        available_indices.insert(i);
    }

    // The result array (0-based), initialized with 1s. This fixes the bug.
    std::vector<int> ans(2 * n, 1);
    
    // Remove the final positions of the 1s from the available set
    // In this solution, they will occupy the last two remaining slots.
    // The loop for i > 1 will determine which slots those are.

    // Place numbers from n down to 2
    for (int i = n; i >= 2; --i) {
        // Iterate backwards through available indices to find a suitable pair
        for (auto it = available_indices.rbegin(); it != available_indices.rend(); ++it) {
            int p2 = *it;
            int p1 = p2 - i;

            // Check if the partner index p1 is also available
            if (available_indices.count(p1)) {
                // Found a pair, place the number i
                ans[p1 - 1] = i;
                ans[p2 - 1] = i;

                // Remove the used indices
                available_indices.erase(p1);
                available_indices.erase(p2);
                
                // Move to the next number
                break; 
            }
        }
    }

    // Print the result
    for (int i = 0; i < 2 * n; ++i) {
        std::cout << ans[i] << (i == 2 * n - 1 ? "" : " ");
    }
    std::cout << "\n";
}

int main() {
    fast_io();
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}