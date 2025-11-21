#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;

    int ucount = 0, lcount = 0;

    for (char c: s) {
        if (isupper(c)) {
            ucount++;
        } else if (islower(c)) {
            lcount++;
        }
    }

    if (ucount > lcount) {
        for (char &ch : s) ch = toupper(ch);
    } else if (lcount > ucount) {
        for (char &ch : s) ch = tolower(ch);
    } else {
        for (char &ch : s) ch = tolower(ch);
    }

    cout << s << endl;
}