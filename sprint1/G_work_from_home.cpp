// Задача G спринта 1. Работа из дома

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>

using namespace std;

void solution(const int number) {
    if (number == 0) {
        cout << "0" << endl;

        return;
    }

    int most_great_bit = 0;
    int temp           = number;

    while (temp != 0) {
        temp >>= 1;
        most_great_bit++;
    }

    for (int i = most_great_bit - 1; i >= 0; i--) {
        cout << (number >> i & 1);
    }

    cout << endl;
}

int main() {
    int number;

    cin >> number;

    solution(number);
}
