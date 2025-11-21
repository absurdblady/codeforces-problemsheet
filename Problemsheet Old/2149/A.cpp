#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int number_of_test_cases;
    cin >> number_of_test_cases;
    while (number_of_test_cases--) {
        int array_size;
        cin >> array_size;
        vector<int> input_array(array_size);
        int negative_count = 0;
        int zero_count = 0;
        long long total_operations = 0;

        for (int i = 0; i < array_size; i++) {
            cin >> input_array[i];
            if (input_array[i] == 0) {
                zero_count++;
                total_operations += 1;
            } else if (input_array[i] == -1) {
                negative_count++;
                total_operations += 2;
            }
        }

        if (negative_count % 2 == 1 && zero_count == 0) {
            total_operations += 2;
        }

        cout << total_operations << "\n";
    }
    return 0;
}