// Задача H спринта 2. Скобочная последовательность

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<char, char> bracket_map = {
    {']', '['},
    {')', '('},
    {'}', '{'}
};

void solution(const string& line) {
    vector<char> stack;

    for (char bracket : line) {
        auto it = bracket_map.find(bracket);

        if (it == bracket_map.end()) {
            stack.push_back(bracket);

            continue;
        }

        if (stack.empty() || stack.back() != it->second) {
            cout << "False" << endl;
            return;
        }

        stack.pop_back();
    }

    if (stack.empty()) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
}

int main() {
    string line;

    getline(cin, line);

    solution(line);
}
