#include <iostream>
#include <string>
using namespace std;

int main() {
    string keys = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

    string message;
    getline(cin, message);

    string decoded = "";

    for (char c: message) {
        if (c == ' ') {
            decoded += ' ';
        } else {
            size_t pos = keys.find(c);
            if (pos != string::npos && pos + 1 < keys.size()) {
                decode
            }
        }
    }
}