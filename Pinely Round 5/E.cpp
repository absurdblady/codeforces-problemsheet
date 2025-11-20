#include <bits/stdc++.h>
using namespace std;

static const int HYPER_IMPORTANT_MODULUS_FOR_RESULTS_998244353 = 998244353;

struct PerWindowAggregatedStateBundle {
    int aggregated_count_of_zero_symbols = 0;
    int aggregated_count_of_one_symbols  = 0;
    int aggregated_count_of_unknown_slots = 0;
    int leftmost_symbol_fixed_value = -1; // -1 unknown, 0 or 1 fixed
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int total_number_of_testcases_to_process;
    if (!(cin >> total_number_of_testcases_to_process)) return 0;

    while (total_number_of_testcases_to_process--) {
        int overall_length_of_entire_string_n;
        int required_window_size_k_odd;
        string initial_pattern_with_zero_one_and_question;
        cin >> overall_length_of_entire_string_n >> required_window_size_k_odd >> initial_pattern_with_zero_one_and_question;

        const int total_number_of_sliding_windows =
            max(0, overall_length_of_entire_string_n - required_window_size_k_odd + 1);

        vector<vector<int>> list_of_window_start_indices_including_position(overall_length_of_entire_string_n);
        for (int window_start_index = 0; window_start_index < total_number_of_sliding_windows; ++window_start_index) {
            for (int offset_inside_window = 0; offset_inside_window < required_window_size_k_odd; ++offset_inside_window) {
                int absolute_position_index = window_start_index + offset_inside_window;
                list_of_window_start_indices_including_position[absolute_position_index].push_back(window_start_index);
            }
        }

        vector<PerWindowAggregatedStateBundle> vector_of_window_state(total_number_of_sliding_windows);
        for (int window_start_index = 0; window_start_index < total_number_of_sliding_windows; ++window_start_index) {
            PerWindowAggregatedStateBundle &ref_state = vector_of_window_state[window_start_index];
            for (int offset_inside_window = 0; offset_inside_window < required_window_size_k_odd; ++offset_inside_window) {
                char c = initial_pattern_with_zero_one_and_question[window_start_index + offset_inside_window];
                if (c == '0') ref_state.aggregated_count_of_zero_symbols++;
                else if (c == '1') ref_state.aggregated_count_of_one_symbols++;
                else ref_state.aggregated_count_of_unknown_slots++;
            }
            char leftmost_char = initial_pattern_with_zero_one_and_question[window_start_index];
            if (leftmost_char == '0') ref_state.leftmost_symbol_fixed_value = 0;
            else if (leftmost_char == '1') ref_state.leftmost_symbol_fixed_value = 1;
            else ref_state.leftmost_symbol_fixed_value = -1;
        }

        auto local_window_feasibility_predicate = [&](const PerWindowAggregatedStateBundle& ws)->bool {
            const int z = ws.aggregated_count_of_zero_symbols;
            const int o = ws.aggregated_count_of_one_symbols;
            const int q = ws.aggregated_count_of_unknown_slots;
            if (ws.leftmost_symbol_fixed_value == 0) {
                if (z + q <= o) return false;
            } else if (ws.leftmost_symbol_fixed_value == 1) {
                if (o + q <= z) return false;
            } else {
                bool ok_if_leftmost_zero = (z + q > o);
                bool ok_if_leftmost_one  = (o + q > z);
                if (!ok_if_leftmost_zero && !ok_if_leftmost_one) return false;
            }
            return true;
        };

        bool any_window_initially_infeasible = false;
        for (int w = 0; w < total_number_of_sliding_windows; ++w) {
            if (!local_window_feasibility_predicate(vector_of_window_state[w])) {
                any_window_initially_infeasible = true;
                break;
            }
        }
        if (any_window_initially_infeasible) {
            cout << 0 << "\n";
            continue;
        }

        vector<int> vector_of_unknown_position_indices;
        vector_of_unknown_position_indices.reserve(overall_length_of_entire_string_n);
        for (int i = 0; i < overall_length_of_entire_string_n; ++i)
            if (initial_pattern_with_zero_one_and_question[i] == '?')
                vector_of_unknown_position_indices.push_back(i);

        sort(vector_of_unknown_position_indices.begin(), vector_of_unknown_position_indices.end(),
             [&](int a, int b){
                 bool a_is_leftmost_of_some_window = (a < total_number_of_sliding_windows);
                 bool b_is_leftmost_of_some_window = (b < total_number_of_sliding_windows);
                 if (a_is_leftmost_of_some_window != b_is_leftmost_of_some_window)
                     return a_is_leftmost_of_some_window > b_is_leftmost_of_some_window;
                 size_t da = list_of_window_start_indices_including_position[a].size();
                 size_t db = list_of_window_start_indices_including_position[b].size();
                 if (da != db) return da > db;
                 return a < b;
             });

        string mutable_working_assignment_string = initial_pattern_with_zero_one_and_question;
        long long accumulated_total_number_of_valid_configurations_mod = 0;

        function<void(int)> depth_first_search_with_aggressive_pruning = [&](int pointer_to_next_unknown_index){
            if (pointer_to_next_unknown_index == (int)vector_of_unknown_position_indices.size()) {
                accumulated_total_number_of_valid_configurations_mod++;
                if (accumulated_total_number_of_valid_configurations_mod >= HYPER_IMPORTANT_MODULUS_FOR_RESULTS_998244353)
                    accumulated_total_number_of_valid_configurations_mod -= HYPER_IMPORTANT_MODULUS_FOR_RESULTS_998244353;
                return;
            }

            int absolute_position_to_assign = vector_of_unknown_position_indices[pointer_to_next_unknown_index];

            for (int bit_choice_value = 0; bit_choice_value <= 1; ++bit_choice_value) {
                char assigned_char = (bit_choice_value == 0 ? '0' : '1');
                mutable_working_assignment_string[absolute_position_to_assign] = assigned_char;

                struct LocalWindowDeltaRecord {
                    int window_id;
                    int dz, do_, dq;
                    int prev_leftmost;
                };
                vector<LocalWindowDeltaRecord> list_of_applied_deltas;
                list_of_applied_deltas.reserve(list_of_window_start_indices_including_position[absolute_position_to_assign].size());

                bool all_touched_windows_still_feasible = true;

                for (int win_id : list_of_window_start_indices_including_position[absolute_position_to_assign]) {
                    PerWindowAggregatedStateBundle &ws = vector_of_window_state[win_id];
                    LocalWindowDeltaRecord rec;
                    rec.window_id = win_id;
                    rec.dz = rec.do_ = 0;
                    rec.dq = 0;
                    rec.prev_leftmost = ws.leftmost_symbol_fixed_value;

                    ws.aggregated_count_of_unknown_slots--;
                    rec.dq = -1;
                    if (assigned_char == '0') { ws.aggregated_count_of_zero_symbols++; rec.dz = +1; }
                    else { ws.aggregated_count_of_one_symbols++; rec.do_ = +1; }

                    if (absolute_position_to_assign == win_id) {
                        ws.leftmost_symbol_fixed_value = (assigned_char == '0' ? 0 : 1);
                    }

                    if (!local_window_feasibility_predicate(ws)) {
                        all_touched_windows_still_feasible = false;
                        for (int idx = (int)list_of_applied_deltas.size(); idx >= 0; --idx) {
                            LocalWindowDeltaRecord r;
                            if (idx == (int)list_of_applied_deltas.size()) r = rec;
                            else r = list_of_applied_deltas[idx];
                            PerWindowAggregatedStateBundle &back = vector_of_window_state[r.window_id];
                            back.aggregated_count_of_zero_symbols += -r.dz;
                            back.aggregated_count_of_one_symbols  += -r.do_;
                            back.aggregated_count_of_unknown_slots+= -r.dq;
                            back.leftmost_symbol_fixed_value = r.prev_leftmost;
                        }
                        break;
                    }
                    list_of_applied_deltas.push_back(rec);
                }

                if (all_touched_windows_still_feasible) {
                    depth_first_search_with_aggressive_pruning(pointer_to_next_unknown_index + 1);
                    for (int idx = (int)list_of_applied_deltas.size() - 1; idx >= 0; --idx) {
                        const LocalWindowDeltaRecord &r = list_of_applied_deltas[idx];
                        PerWindowAggregatedStateBundle &back = vector_of_window_state[r.window_id];
                        back.aggregated_count_of_zero_symbols += -r.dz;
                        back.aggregated_count_of_one_symbols  += -r.do_;
                        back.aggregated_count_of_unknown_slots+= -r.dq;
                        back.leftmost_symbol_fixed_value = r.prev_leftmost;
                    }
                }
                mutable_working_assignment_string[absolute_position_to_assign] = '?';
            }
        };

        depth_first_search_with_aggressive_pruning(0);

        cout << (accumulated_total_number_of_valid_configurations_mod % HYPER_IMPORTANT_MODULUS_FOR_RESULTS_998244353) << "\n";
    }

    return 0;
}
