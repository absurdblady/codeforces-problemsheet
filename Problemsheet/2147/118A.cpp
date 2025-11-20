#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    string vowels = "aeiouyAEIOUY";
    string result;

    for (char c: s) {
        if (vowels.find(c) == string::npos) { // npos is not found if no vowels found in C, then concatenate words and .
            result += '.';
            result += tolower(c);
        } 
    }

    cout << result << "\n";
    return 0;
}