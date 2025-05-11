// Финальная задача B спринта 2. Калькулятор

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

void get_stack_values(int& value1, int&value2, stack<int>& stack) {
    value1 = stack.top();
    stack.pop();
    value2 = stack.top();
    stack.pop();
}

int div_floor(const int value1, const int value2) {
    if (value1 < 0 != value2 < 0 && value1 % value2 != 0) {
        return value1 / value2 - 1;
    }

    return value1 / value2;
}

int solution(const string& line) {
    istringstream iss(line);
    string word;
    stack<int> stack;

    while (iss >> word) {
        int value1, value2;

        if (word == "+") {
            get_stack_values(value1, value2, stack);
            stack.push(value2 + value1);
            continue;
        }

        if (word == "-") {
            get_stack_values(value1, value2, stack);
            stack.push(value2 - value1);
            continue;
        }

        if (word == "*") {
            get_stack_values(value1, value2, stack);
            stack.push(value2 * value1);
            continue;
        }

        if (word == "/") {
            get_stack_values(value1, value2, stack);
            stack.push(div_floor(value2, value1));
            continue;
        }

        stack.push(stoi(word));
    }

    return stack.top();
}

void print(const int result) {
    cout << result << endl;
}

int main() {
    string line;

    getline(cin, line);

    print(solution(line));
}
