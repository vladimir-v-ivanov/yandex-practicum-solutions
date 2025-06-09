// Задача K спринта 4. МногоГоша

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;

    while (exp) {
        if (exp % 2) {
            result = result * base % mod;
        }

        base = base * base % mod;
        exp /= 2;
    }

    return result;
}

int main() {
    freopen("input.txt", "r", stdin);

    int    n, k;
    string line;
    cin >> n >> k;
    cin.ignore();
    getline(cin, line);

    constexpr int m    = 1000000007;
    constexpr int q    = 911;
    long long     hash = 0;

    for (int i = 0; i < n; i++) {
        hash = (hash * q + line[i]) % m;
    }

    unordered_map<long long, pair<int, int>> mapa;
    vector<int> indexes;
    mapa[hash] = make_pair(0, 1);

    for (int i = n; i < line.length(); i++) {
        const long long pow_q    = mod_pow(q, n - 1, m);
        const long long removed  = 1LL * line[i - n] * pow_q % m;
        long long       tmp_hash = (hash - removed + m) % m;
        tmp_hash                 = tmp_hash * q % m;
        hash                     = (tmp_hash + line[i]) % m;

        if (!mapa.contains(hash)) {
            mapa[hash] = {i - n + 1, 1};
        } else {
            mapa[hash].second++;

            if (mapa[hash].second == k) {
                indexes.push_back(mapa[hash].first);
            }
        }
    }

    for (const auto index : indexes) {
        cout << index << " ";
    }

    cout << endl;
}
