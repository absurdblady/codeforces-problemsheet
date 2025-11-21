#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(2 * n, 0);
        int idx = 0;

        for (int x = 1; x <= n; x++) {
            arr[idx] = x;
            arr[idx + x] = x;
            idx++;
        }

        for (int i = 0; i < 2 * n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
