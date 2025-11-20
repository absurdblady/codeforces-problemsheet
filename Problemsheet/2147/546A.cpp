#include <iostream>
using namespace std;

int main() {
    int k, n, w;
    cin >> k >> n >> w;

    int x = 0;

    for (int i=1; i <= w; i++) {
        x += k*i;
    }

    if (x > n) {
        x = x - n;
    } else {
        x = 0;
    }

    cout << x << endl;
}