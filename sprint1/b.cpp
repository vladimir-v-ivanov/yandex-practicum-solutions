// Задача B спринта 1. Четные и нечетные числа

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

bool is_parity(const int a, const int b, const int c) {
    const int parity = abs(a) % 2;

    return abs(b) % 2 == parity && abs(c) % 2 == parity;
}

void print(const bool is_parity) {
    cout << (is_parity ? "WIN" : "FAIL") << endl;
}

int main() {
    int a, b, c;

    cin >> a >> b >> c;

    print(is_parity(a, b, c));
}
