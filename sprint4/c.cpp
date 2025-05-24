// Задача C спринта 4. Странное сравнение

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    string line1, line2;
    unordered_map<char, char> map1;
    unordered_map<char, char> map2;
    getline(cin, line1);
    getline(cin, line2);

    if (line1.length() != line2.length()) {
        cout << "NO" << endl;
        return 0;
    }

    for (int i = 0; i < line1.length(); i++) {
        if (!map1.contains(line1[i]) && !map2.contains(line2[i])) {
            map1[line1[i]] = line2[i];
            map2[line2[i]] = line1[i];
        } else if (map1[line1[i]] != line2[i] || map2[line2[i]] != line1[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}
