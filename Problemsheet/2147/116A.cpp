#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int current_passengers = 0;
    int max_passengers = 0;

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        current_passengers = current_passengers - a + b;
        max_passengers = max(max_passengers, current_passengers);
    }

    cout << max_passengers << endl;

    return 0;
}