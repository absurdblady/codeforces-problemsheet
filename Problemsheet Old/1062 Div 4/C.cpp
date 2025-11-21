#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<long long> a(n);

        bool hasOdd = false, hasEven = false;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] % 2 == 0) hasEven = true;
            else hasOdd = true;
        }

        vector<long long> sortedArr = a;
        sort(sortedArr.begin(), sortedArr.end());

        if(hasOdd && hasEven && sortedArr != a) {
            for(long long &x : sortedArr)
                cout << x << " ";
        } else {
            for(long long &x : a)
                cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
