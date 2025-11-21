#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int number_of_test_cases_total;
    cin >> number_of_test_cases_total;

    while (number_of_test_cases_total--) {
        long long initial_rating_of_vasya;
        long long division_cutoff_rating_threshold_X;
        long long maximum_single_round_rating_delta_D;
        int total_number_of_rounds_n;

        cin >> initial_rating_of_vasya
            >> division_cutoff_rating_threshold_X
            >> maximum_single_round_rating_delta_D
            >> total_number_of_rounds_n;

        string round_type_sequence_string;
        cin >> round_type_sequence_string;

        long long possible_rating_interval_min_inclusive = initial_rating_of_vasya;
        long long possible_rating_interval_max_inclusive = initial_rating_of_vasya;

        int maximum_count_of_rated_rounds_vasya_can_get = 0;

        for (char current_round_type_char : round_type_sequence_string) {
            if (current_round_type_char == '1') {
                possible_rating_interval_min_inclusive =
                    max(0LL, possible_rating_interval_min_inclusive - maximum_single_round_rating_delta_D);
                possible_rating_interval_max_inclusive =
                    possible_rating_interval_max_inclusive + maximum_single_round_rating_delta_D;
                ++maximum_count_of_rated_rounds_vasya_can_get;
            } else { // '2'
                if (possible_rating_interval_min_inclusive < division_cutoff_rating_threshold_X) {

                    long long capped_high_before =
                        min(possible_rating_interval_max_inclusive, division_cutoff_rating_threshold_X - 1);

                    possible_rating_interval_min_inclusive =
                        max(0LL, possible_rating_interval_min_inclusive - maximum_single_round_rating_delta_D);
                    possible_rating_interval_max_inclusive =
                        capped_high_before + maximum_single_round_rating_delta_D;

                    ++maximum_count_of_rated_rounds_vasya_can_get;
                } else {
                    // Unrated div2 round: range does not change
                    // (no rating updates allowed)
                }
            }
        }

        cout << maximum_count_of_rated_rounds_vasya_can_get << '\n';
    }
    return 0;
}
