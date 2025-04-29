// Задача F спринта 1. Палиндром

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <cctype>
#include <iostream>
#include <sstream>

using namespace std;

bool solution(const string& line) {
    int i = 0, j = line.length() - 1;

    while (i < j) {
        if (!isalnum(line[i])) {
            ++i;
            continue;
        }

        if (!isalnum(line[j])) {
            --j;
            continue;
        }

        if (tolower(line[i]) != tolower(line[j])) {
            return false;
        }

        i++;
        j--;
    }

    return true;
}

void print(const bool is_palindrome) {
    cout << (is_palindrome ? "True" : "False") << endl;
}

int main() {
    string line;

    getline(cin, line);

    print(solution(line));
}
