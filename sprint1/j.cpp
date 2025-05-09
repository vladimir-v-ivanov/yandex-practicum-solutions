// Задача J спринта 1. Факторизация

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>

using namespace std;

void solution(int number) {
    for (int i = 2; i * i <= number; ++i) {
        while (number % i == 0) {
            number /= i;
            cout << i << " ";
        }
    }

    if (number != 1) {
        cout << number << " ";
    }

    cout << endl;
}

int main() {
    int number;

    cin >> number;

    solution(number);
}
