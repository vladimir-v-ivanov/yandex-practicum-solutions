// Задача G спринта 2. Стек - MaxEffective

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string      line;
    string      word;
    vector<int> main_stack;
    vector<int> max_stack;

    getline(cin, line);
    const int num = stoi(line);

    for (int i = 0; i < num; i++) {
        getline(cin, line);
        istringstream iss(line);
        iss >> word;

        if (word == "get_max") {
            if (max_stack.empty()) {
                cout << "None\n";
                continue;
            }

            cout << max_stack.back() << "\n";
        }

        if (word == "push") {
            iss >> word;
            const int value = stoi(word);

            main_stack.push_back(value);
            max_stack.push_back(max_stack.empty() || value > max_stack.back() ? value : max_stack.back());
        }

        if (word == "pop") {
            if (main_stack.empty()) {
                cout << "error\n";
                continue;
            }

            main_stack.pop_back();
            max_stack.pop_back();
        }

        if (word == "top") {
            if (main_stack.empty()) {
                cout << "error\n";
                continue;
            }

            cout << main_stack.back() << "\n";
        }
    }
}
