#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, h;
    cin >> n >> h;

    vector<int> height(n);
    for (int i = 0; i < n; ++i) {
        cin >> height[i];
    }

    int bent = 0;
    for (int i = 0; i < n; ++i) {
        if (height[i] > h) {
            bent = bent + 2;
        } else {
            bent = bent + 1;
        }
    }

    cout << bent << endl;

    return 0;
}