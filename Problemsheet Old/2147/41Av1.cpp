#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;

void reverseString(string& str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        swap(str[left], str[right]);
        left++;
        right--;
    }
}

int main() {
    string myString;
    cin >> myString;

    string original;
    original = myString;
    
    reverseString(myString);
    if (original == myString) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}