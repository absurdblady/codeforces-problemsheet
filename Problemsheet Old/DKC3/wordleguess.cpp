#include <bits/stdc++.h>
using namespace std;

int main() {
    string hidden;
    int N;
    cin >> hidden >> N;

    while (N--) {
        string guess;
        cin >> guess;

        string feedback(5, 'X');
        map<char, int> letterCount;
        for (char c : hidden) letterCount[c]++;

        // Pass 1: Green check
        for (int i = 0; i < 5; i++) {
            if (guess[i] == hidden[i]) {
                feedback[i] = 'G';
                letterCount[guess[i]]--;
            }
        }

        // Pass 2: Yellow check
        for (int i = 0; i < 5; i++) {
            if (feedback[i] == 'G') continue;
            char c = guess[i];
            if (letterCount[c] > 0) {
                feedback[i] = 'Y';
                letterCount[c]--;
            }
        }

        cout << feedback << "\n";
    }

    return 0;
}
