#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    vector<int> max_combination;

    int combination1 = a + b * c;
    max_combination.push_back(combination1);

    int combination2 = a * (b + c);
    max_combination.push_back(combination2);

    int combination3 = a * b * c;
    max_combination.push_back(combination3);

    int combination4 = (a + b) * c;
    max_combination.push_back(combination4);

    sort(max_combination.begin(), max_combination.end());

    cout << max_combination.back();  // largest value

    return 0;
}
