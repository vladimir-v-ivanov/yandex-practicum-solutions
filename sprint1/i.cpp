// Задача I спринта 1. Степень четырех

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>

using namespace std;

bool solution(int number) {
    while (number != 1) {
        if (number % 4 != 0) {
            return false;
        }

        number /= 4;
    }

    return true;
}

void print(const bool is_power_of_four) {
    cout << (is_power_of_four ? "True" : "False") << endl;
}

int main() {
    int number;

    cin >> number;

    print(solution(number));
}
