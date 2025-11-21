#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_test_cases;
    cin >> num_test_cases;
    while (num_test_cases--) {
        int sequence_size;
        cin >> sequence_size;

        if (sequence_size == 1) {
            cout << "1 1\n";
            continue;
        }
        if (sequence_size == 2) {
            cout << "1 2 1 2\n";
            continue;
        }
        if (sequence_size == 3) {
            cout << "1 3 1 2 3 2\n";
            continue;
        }

        vector<int> result_sequence(2 * sequence_size, 0);
        int insertion_point = 0;
        for (int i = 1; i <= sequence_size; ++i) {
            result_sequence[insertion_point] = i;
            result_sequence[insertion_point + i] = i;
            insertion_point++;
        }

        for (size_t i = 0; i < 2 * sequence_size; ++i) {
            cout << result_sequence[i] << (i + 1 == 2 * sequence_size ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}
