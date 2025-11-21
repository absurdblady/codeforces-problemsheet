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

        // The previous logic for sequence_size > 3 was incorrect.
        // This is a corrected greedy algorithm that places numbers
        // from largest to smallest to avoid collisions.
        vector<int> result_sequence(2 * sequence_size, 0);

        for (int i = sequence_size; i >= 1; --i) {
            int first_pos = -1;
            for (int j = 0; j < 2 * sequence_size; ++j) {
                if (result_sequence[j] == 0 && (j + i + 1) < 2 * sequence_size && result_sequence[j + i + 1] == 0) {
                    first_pos = j;
                    break;
                }
            }
            if (first_pos != -1) {
                result_sequence[first_pos] = i;
                result_sequence[first_pos + i + 1] = i;
            }
        }

        for (size_t i = 0; i < 2 * sequence_size; ++i) {
            cout << result_sequence[i] << (i + 1 == 2 * sequence_size ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}
