// Задача A спринта 1. Значения функции

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>
#include <sstream>

using namespace std;

int solution(const int a, const int x, const int b, const int c) {
    return a * (x * x) + b * x + c;
}

void print(const int result) {
    cout << result << endl;
}

int main() {
    int a, x, b, c;

    cin >> a >> x >> b >> c;

    print(solution(a, x, b, c));
}
