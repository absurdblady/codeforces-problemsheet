// if problem 122A would have in input case of 1<=n<=10^6

#include <bits/stdc++.h>
using namespace std;

vector<long long> lucky;

void generate(long long x, long long limit) {
    if (x > limit) return;
    if (x != 0) lucky.push_back(x);
    generate(x * 10+4, limit);
    generate(x * 10+7, limit);
}

int main() {
    long long n;
    cin >> n;

    generate(0, 1000000);

    for (long long x: lucky) {
        if (n%x == 0) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}