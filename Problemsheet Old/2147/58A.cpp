#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    string s, hello = "hello";
    cin >> s;

    int j = 0;
    for (int i = 0; j<s.length(); i++){
        if (s[i]==hello[i]) j++;
        if (j==5) break;
    }

    cout << (j==5? "YES":"NO") << endl;
    return 0;

}