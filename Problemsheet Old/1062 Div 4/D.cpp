#include <bits/stdc++.h>
using namespace std;

long long compute_gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int number_of_test_cases;
    cin >> number_of_test_cases;

    while (number_of_test_cases--) {
        int length_of_array;
        cin >> length_of_array;

        vector<long long> array_of_values(length_of_array);
        long long gcd_of_entire_array = 0;

        for (int i = 0; i < length_of_array; i++) {
            cin >> array_of_values[i];
            gcd_of_entire_array = (i == 0) ? array_of_values[i] : compute_gcd(gcd_of_entire_array, array_of_values[i]);
        }

        if (gcd_of_entire_array > 1) {
            cout << -1 << "\n";
            continue;
        }

        // Try values of x from 2 up to a safe upper bound
        const long long maximum_attempt_value = 2000000;
        long long smallest_valid_result = -1;

        for (long long possible_candidate = 2; possible_candidate <= maximum_attempt_value; possible_candidate++) {
            bool exists_value_with_coprime = false;

            for (long long number_in_array : array_of_values) {
                if (compute_gcd(number_in_array, possible_candidate) == 1) {
                    exists_value_with_coprime = true;
                    break;
                }
            }

            if (exists_value_with_coprime) {
                smallest_valid_result = possible_candidate;
                break;
            }
        }

        cout << smallest_valid_result << "\n";
    }

    return 0;
}
