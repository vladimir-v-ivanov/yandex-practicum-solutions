// Задача I спринта 3. Любители конференций

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void solution(const vector<int>& univers, const int k) {
    unordered_map<int, int> map;

    for (const int id : univers) {
        map[id]++;
    }

    vector<pair<int, int>> frequencies;

    for (const auto& [first, second] : map) {
        frequencies.emplace_back(first, second);
    }

    ranges::stable_sort(frequencies, [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second == b.second ? a.first < b.first : a.second > b.second;
    });

    for (int i = 0; i < k && i < frequencies.size(); i++) {
        cout << frequencies[i].first << " ";
    }
}

int main() {
    int len, k, num;
    vector<int> univers;

    cin >> len;
    univers.reserve(len);

    for (int i = 0; i < len; i++) {
        cin >> num;
        univers.push_back(num);
    }

    cin >> k;

    solution(univers, k);
}
