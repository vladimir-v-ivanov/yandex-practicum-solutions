// Задача L спринта 1. Лишняя буква

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>

using namespace std;

char solution(const string& line1, const string& line2) {
    int result = 0;

    for (const char c : line1) {
        result ^= c;
    }

    for (const char c : line2) {
        result ^= c;
    }

    return static_cast<char>(result);
}

void print(const char letter) {
    cout << letter << endl;
}

int main() {
    string line1;
    string line2;

    getline(cin, line1);
    getline(cin, line2);

    print(solution(line1, line2));
}
