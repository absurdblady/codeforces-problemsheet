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
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());

        long long alice = 0, bob = 0;
        bool turnAlice = true;

        int i = n - 1;
        while (i >= 0) {
            long long h = a[i];
            int cnt = 0;
            while (i >= 0 && a[i] == h) {
                cnt++;
                i--;
            }
            long long next = (i >= 0 ? a[i] : 0);
            long long moves = h - next;

            long long totalGain = 1LL * cnt * moves;

            if (turnAlice) alice += totalGain;
            else bob += totalGain;

            if (moves % 2 == 1) turnAlice = !turnAlice;
        }

        cout << alice << " " << bob << "\n";
    }
    return 0;
}
