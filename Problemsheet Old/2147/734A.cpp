#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int anton = 0, danik = 0;
    for (char c : s) {
        if (c == 'A') anton++;
        else if (c == 'D') danik++;
    }

    if (anton > danik) cout << "Anton\n";
    else if (danik > anton) cout << "Danik\n";
    else cout << "Friendship\n";

    return 0;
}
