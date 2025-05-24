// Задача D спринта 4. Полиномиальный хеш

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>

using namespace std;

int main() {
    int a, m;
    string s;
    long long result = 0;

    cin >> a >> m >> s;

    for (const char c : s) {
        result = (result * a + c) % m;
    }

    cout << result << endl;
}
