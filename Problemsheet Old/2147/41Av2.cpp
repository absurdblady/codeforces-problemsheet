#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// This function checks if a string is a palindrome
bool isPalindrome(const string& str) {
    string reversed_str = str;
    reverse(reversed_str.begin(), reversed_str.end());
    return str == reversed_str;
}

int main() {
    string a, b;
    cin >> a;
    cin >> b;

    // First, check if the two strings have the same length
    if (a.length() != b.length()) {
        cout << "NO" << endl;
        return 0;
    }

    // Check if the characters are the same by sorting both strings
    // and then comparing them.
    string sorted_a = a;
    string sorted_b = b;
    sort(sorted_a.begin(), sorted_a.end());
    sort(sorted_b.begin(), sorted_b.end());

    if (sorted_a != sorted_b) {
        cout << "NO" << endl;
        return 0;
    }
    
    // Now check if they are reverses of each other
    string reversed_a = a;
    reverse(reversed_a.begin(), reversed_a.end());

    if (reversed_a == b) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}