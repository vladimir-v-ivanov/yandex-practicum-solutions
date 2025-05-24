// Задача I спринта 4. Анаграммная группировка

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

long long hash_string(const string& s) {
    long long result = 0;

    for (const char c : s) {
        constexpr long long m = 1000000007;
        constexpr long long a = 4294967296;
        result                = (result * a + c) % m;
    }

    return result;
}

int main() {
    int len;
    cin >> len;

    unordered_map<long long, vector<int>> map;
    vector<long long>                     keys;

    for (int i = 0; i < len; i++) {
        string s;
        cin >> s;

        ranges::sort(s);
        const long long sum = hash_string(s);

        if (!map.contains(sum)) {
            keys.push_back(sum);
        }

        map[sum].push_back(i);
    }

    for (const auto& key : keys) {
        for (vector<int> indexes = map[key]; int value : indexes) {
            cout << value << " ";
        }

        cout << "\n";
    }
}
