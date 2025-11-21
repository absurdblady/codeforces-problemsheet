#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    string t;
    cin >> t;

void reverse_string_manual(std::string& s) {
    int start = 0;
    int end = s.length() - 1;

    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        
        start++;
        end--;
    }
}

    return 0;
}