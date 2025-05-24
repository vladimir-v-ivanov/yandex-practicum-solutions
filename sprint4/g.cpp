// Задача G спринта 4. Сумма четверок

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int len, s;
    cin >> len >> s;

    vector<long long> nums(len);
    set<vector<long long>> quadruples;
    unordered_map<long long, vector<pair<int, int>>> pair_sums;

    for (int i = 0; i < len; i++) {
        long long num;
        cin >> num;
        nums[i] = num;
    }

    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            long long target = s - nums[i] - nums[j];

            if (pair_sums.contains(target)) {
                for (auto [k, l] : pair_sums[target]) {
                    if (k != i && k != j && l != i && l != j) {
                        vector quadruple {nums[k], nums[l], nums[i], nums[j]};
                        ranges::sort(quadruple.begin(), quadruple.end());
                        quadruples.insert(quadruple);
                    }
                }
            }
        }

        for (int j = 0; j < i; j++) {
            long long sum = nums[i] + nums[j];
            pair_sums[sum].emplace_back(j, i);
        }
    }

    cout << quadruples.size() << "\n";

    for (auto quadruple : quadruples) {
        cout << quadruple[0] << " " << quadruple[1] << " " << quadruple[2] << " " << quadruple[3] << "\n";
    }
}
