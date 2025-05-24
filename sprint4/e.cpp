// Задача E спринта 4. Сломай меня

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>
#include <unordered_map>

using namespace std;

long long hash_string(const string& s) {
    long long result = 0;

    for (const char c : s) {
        constexpr int m = 123987123;
        constexpr int a = 1000;
        result          = (result * a + c) % m;
    }

    return result;
}

void get_string(const int len, const string& prefix, unordered_map<long long, string>& map) {
    if (len == 0) {
        if (const long long hash = hash_string(prefix); map.contains(hash)) {
            if (map[hash] != prefix) {
                cout << map[hash] << " - " << prefix << endl;
            }
        } else {
            map[hash] = prefix;
        }

        return;
    }

    for (char i = 'a'; i <= 'z'; i++) {
        get_string(len - 1, prefix + string(1, i), map);
    }
}

int main() {
    string s1;
    string s2;
    unordered_map<long long, string> map;

    get_string(10, "", map);
}
