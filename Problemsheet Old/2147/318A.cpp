#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k; 
    cin >> n >> k;

    vector<int> v;

    // odd numbers
    for (int i = 1; i <= n; i += 2) {
        v.push_back(i);
    }

    // even numbers
    for (int i = 2; i <= n; i += 2) {
        v.push_back(i);
    }

    // for (int x : v) cout << x << " ";

    cout << v[k-1];
    return 0;
}
