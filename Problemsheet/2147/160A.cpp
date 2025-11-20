#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int totalSum = 0;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
        totalSum = totalSum + coins[i];
    }
    /*
    // calculating the total
    cout << totalSum << "\n";

    for (int x : coins) cout << x << " ";
    */

    
    // sorting the array; descending
    sort(coins.begin(), coins.end(), greater<int>());
    
    int mySum = 0;
    int count = 0;
    for (int x : coins){
        mySum = mySum + x;
        count = count + 1;
        if (mySum > totalSum - mySum) {
            cout << count;
            return 0;
        }
    } 

    return 0;
}