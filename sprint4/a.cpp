// Задача A спринта 4. Кружки

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    string line;
    vector<string> keys;
    unordered_map<string, int> map;

    getline(cin, line);
    const int len = stoi(line);

    for (int i = 0; i < len; i++) {
        string name;
        getline(cin, name);

        if (map[name] == 0) {
            keys.push_back(name);
        }

        map[name]++;
    }

    for (const auto& key : keys) {
        cout << key << "\n";
    }
}
