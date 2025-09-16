#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> scores(n);
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }


    int kth_score = scores [k-1];
    int advancing_count = 0;

    for (int i = 0; i < n; i++) {
        if (scores[i] >= kth_score && scores[i] > 0) {
            advancing_count++;
        }
    }

    cout << advancing_count << endl;

    return 0;
}