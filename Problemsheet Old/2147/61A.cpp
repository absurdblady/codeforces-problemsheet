#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a;
    cin >> b;

    vector<int> lista;
    vector<int> listb;
    vector<int> listans;

    for (char c : a) lista.push_back(c-'0');
    for (char c : b) listb.push_back(c-'0');

    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i]) {
            listans.push_back(0);
        } else {
            listans.push_back(1);
        }
    }

    for (int x : listans) cout << x;
    return 0;
}