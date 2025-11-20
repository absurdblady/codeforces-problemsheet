#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;

    // canPass[level] = true means either X or Y can pass this level.
    vector<bool> canPass(n + 1, false);

    int lvlX;
    cin >> lvlX;
    for (int i = 0; i < lvlX; i++) {
        int lvlNum;
        cin >> lvlNum;
        canPass[lvlNum] = true;
    }

    int lvlY;
    cin >> lvlY;
    for (int i = 0; i < lvlY; i++) {
        int lvlNum;
        cin >> lvlNum;
        canPass[lvlNum] = true;
    }

    // checking if all level from 1 to n are covered
    bool allCovered = true;
    for (int l = 1; l <= n; l++) {
        if(!canPass[l]) {
            allCovered = false;
            break;
        }
    }

    if (allCovered) {
        cout << "I become the guy.\n";
    } else {
        cout << "Oh, my keyboard!\n";
    }

    return 0;
}