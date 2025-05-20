// Задача N спринта 3. Клумбы

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

vector<pair<int, int>> solution(const vector<pair<int, int>>& pairs) {
    if (pairs.size() == 1) {
        return pairs;
    }

    const int mid = static_cast<int>(pairs.size() / 2);

    vector left(pairs.begin(), pairs.begin() + mid);
    left = solution(left);

    vector right(pairs.begin() + mid, pairs.end());
    right = solution(right);

    vector<pair<int, int>> result;
    result.reserve(pairs.size());

    int i = 0;
    int j = 0;

    while (i < left.size() && j < right.size()) {
        if (!result.empty() && left[i].first <= result.back().second) {
            result.back().second = max(left[i].second, result.back().second);
            i++;

            continue;
        }

        if (!result.empty() && right[j].first <= result.back().second) {
            result.back().second = max(right[j].second, result.back().second);
            j++;

            continue;
        }

        if (left[i] <= right[j]) {
            result.push_back(left[i]);
            i++;
        } else {
            result.push_back(right[j]);
            j++;
        }
    }

    while (i < left.size()) {
        if (!result.empty() && left[i].first <= result.back().second) {
            result.back().second = max(result.back().second, left[i].second);
        } else {
            result.push_back(left[i]);
        }

        i++;
    }

    while (j < right.size()) {
        if (!result.empty() && right[j].first <= result.back().second) {
            result.back().second = max(result.back().second, right[j].second);
        } else {
            result.push_back(right[j]);
        }

        j++;
    }

    return result;
}

void print(const vector<pair<int, int>>& pairs) {
    for (const auto& [first, second] : pairs) {
        cout << first << " " << second << "\n";
    }
}

int main() {
    int len, num1, num2;
    cin >> len;
    vector<pair<int, int>> pairs;

    pairs.reserve(len);

    for (int i = 0; i < len; i++) {
        cin >> num1 >> num2;
        pairs.emplace_back(num1, num2);
    }

    print(solution(pairs));
}
