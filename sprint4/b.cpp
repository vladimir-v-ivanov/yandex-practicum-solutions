// Задача B спринта 4. Соревнование

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int                     len, num, zeroes = 0, ones = 0, longest = 0;
    unordered_map<int, int> map;
    cin >> len;
    map[0] = -1;

    for (int i = 0; i < len; i++) {
        cin >> num;

        if (num == 0) {
            zeroes++;
        } else if (num == 1) {
            ones++;
        }

        if (int sum = zeroes - ones; !map.contains(sum)) {
            map[sum] = i;
        } else {
            longest = max(longest, i - map[sum]);
        }
    }

    cout << longest << endl;
}
