// Задача L спринта 2. Фибоначчи по модулю

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <cmath>
#include <iostream>

using namespace std;

int solution(const int k, const int number) {
    if (number < 2) {
        return 1;
    }

    const int mod = static_cast<int>(pow(10, k));
    int a = 0;
    int b = 1;

    for (int i = 0; i < number; i++) {
        const int t = (a + b) % mod;
        a = b;
        b = t;
    }

    return b;
}

void print(const int k, const int number) {
    cout << number % static_cast<int>(pow(10, k)) << endl;
}

int main() {
    int number;
    int k;
    cin >> number;
    cin >> k;

    print(k, solution(k, number));
}
