// Задача F спринта 2. Стек - Max

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <climits>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string      line;
    string      word;
    vector<int> stack;

    getline(cin, line);
    const int num = stoi(line);

    for (int i = 0; i < num; i++) {
        getline(cin, line);
        istringstream iss(line);
        iss >> word;

        if (word == "get_max") {
            if (stack.empty()) {
                cout << "None\n";
                continue;
            }

            int max = INT_MIN;

            for (const int j : stack) {
                if (j > max) {
                    max = j;
                }
            }

            cout << max << "\n";
        }

        if (word == "push") {
            iss >> word;
            stack.push_back(stoi(word));
        }

        if (word == "pop") {
            if (stack.empty()) {
                cout << "error\n";
                continue;
            }

            stack.pop_back();
        }

        if (word == "top") {
            if (stack.empty()) {
                cout << "error\n";
                continue;
            }


        }
    }
}
