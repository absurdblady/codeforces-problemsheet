#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int extremely_total_testcase_counter; 
    if (!(cin >> extremely_total_testcase_counter)) return 0;

    while (extremely_total_testcase_counter--) {
        long long count_of_items_in_this_case, loyalty_boundary_X_value;
        cin >> count_of_items_in_this_case >> loyalty_boundary_X_value;

        vector<long long> vector_of_all_item_prices(count_of_items_in_this_case);
        for (auto &single_price_being_read : vector_of_all_item_prices) {
            cin >> single_price_being_read;
        }


        vector<long long> vector_of_decided_purchase_order;
        vector_of_decided_purchase_order.reserve(count_of_items_in_this_case);


        vector<long long> duplicate_prices_sorted_ascending = vector_of_all_item_prices;
        sort(duplicate_prices_sorted_ascending.begin(), duplicate_prices_sorted_ascending.end());


        priority_queue<long long> maximum_choice_heap;
        for (long long val : vector_of_all_item_prices) maximum_choice_heap.push(val);


        unordered_map<long long, long long> how_many_times_value_is_used;
        auto mark_used = [&](long long v){ how_many_times_value_is_used[v]++; };
        auto is_available = [&](long long v){ 
            return how_many_times_value_is_used[v] < 
                   (long long)(count(vector_of_all_item_prices.begin(), vector_of_all_item_prices.end(), v));
        };


        unordered_map<long long,long long> total_frequency_map;
        total_frequency_map.reserve(vector_of_all_item_prices.size()*2);
        for (auto v: vector_of_all_item_prices) total_frequency_map[v]++;

        auto is_available_fast = [&](long long v)->bool {
            auto used = how_many_times_value_is_used.find(v);
            long long used_cnt = (used==how_many_times_value_is_used.end()?0:used->second);
            return used_cnt < total_frequency_map[v];
        };

        long long pointer_for_smallest_feasible = 0;
        long long current_running_sum_S = 0;

  
        auto advance_pointer_to_unused = [&](){
            while (pointer_for_smallest_feasible < (long long)duplicate_prices_sorted_ascending.size() &&
                   !is_available_fast(duplicate_prices_sorted_ascending[pointer_for_smallest_feasible])) {
                ++pointer_for_smallest_feasible;
            }
        };

        for (long long items_taken_so_far = 0; items_taken_so_far < count_of_items_in_this_case; ++items_taken_so_far) {
            advance_pointer_to_unused();

            bool could_take_non_crossing = false;
            long long candidate_value_to_take = -1;

            if (pointer_for_smallest_feasible < (long long)duplicate_prices_sorted_ascending.size()) {
                long long smallest_unused_price = duplicate_prices_sorted_ascending[pointer_for_smallest_feasible];

                long long loyalty_before = current_running_sum_S / loyalty_boundary_X_value;
                long long loyalty_after  = (current_running_sum_S + smallest_unused_price) / loyalty_boundary_X_value;
                if (loyalty_after == loyalty_before) {
                    could_take_non_crossing = true;
                    candidate_value_to_take = smallest_unused_price;
                }
            }

            if (could_take_non_crossing) {

                vector_of_decided_purchase_order.push_back(candidate_value_to_take);
                mark_used(candidate_value_to_take);
                current_running_sum_S += candidate_value_to_take;
            } else {

                while (!maximum_choice_heap.empty() && !is_available_fast(maximum_choice_heap.top())) {
                    maximum_choice_heap.pop();
                }
                long long biggest_available_price = maximum_choice_heap.top();
                maximum_choice_heap.pop();

                vector_of_decided_purchase_order.push_back(biggest_available_price);
                mark_used(biggest_available_price);
                current_running_sum_S += biggest_available_price;
            }
        }

        long long magnificently_accumulated_bonus_points = 0;
        long long rolling_sum_for_bonus = 0;
        for (long long price_now : vector_of_decided_purchase_order) {
            long long level_before = rolling_sum_for_bonus / loyalty_boundary_X_value;
            long long level_after  = (rolling_sum_for_bonus + price_now) / loyalty_boundary_X_value;
            if (level_after > level_before) {
 
                magnificently_accumulated_bonus_points += price_now;
            }
            rolling_sum_for_bonus += price_now;
        }

        cout << magnificently_accumulated_bonus_points << "\n";
        for (size_t i = 0; i < vector_of_decided_purchase_order.size(); ++i) {
            if (i) cout << ' ';
            cout << vector_of_decided_purchase_order[i];
        }
        cout << "\n";
    }
    return 0;
}
