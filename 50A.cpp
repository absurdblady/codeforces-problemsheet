#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    int total_area = m*n;
    int max_dominoes = total_area / 2;
    cout << max_dominoes << endl;

    return 0;
}