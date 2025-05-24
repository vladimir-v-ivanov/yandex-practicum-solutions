// Задача F спринта 4. Префиксные хеши

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long substring_hash(
    const vector<long long>& hashes,
    const vector<long long>& powers,
    const int                begin,
    const int                end,
    const int                m
) {
    if (begin == 0) {
        return hashes[end];
    }

    const long long sub = hashes[begin - 1] * powers[end - begin + 1] % m;

    return (hashes[end] - sub + m) % m;
}

int main() {
    int    a, m, len;
    string s;
    cin >> a >> m >> s >> len;

    const unsigned long n = s.length();
    vector<long long>   hashes(n);
    vector<long long>   powers(n);

    powers[0] = 1;
    for (int i = 1; i < n; ++i) {
        powers[i] = powers[i - 1] * a % m;
    }

    hashes[0] = static_cast<unsigned char>(s[0]);
    for (int i = 1; i < n; ++i) {
        hashes[i] = (hashes[i - 1] * a + static_cast<unsigned char>(s[i])) % m;
    }

    for (int i = 0; i < len; ++i) {
        int begin, end;
        cin >> begin >> end;
        begin--;
        end--;

        cout << substring_hash(hashes, powers, begin, end, m) << '\n';
    }

    return 0;
}
