// Задача K спринта 2. Рекурсивные числа Фибоначчи

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>

using namespace std;

int solution(const int number) {
    if (number < 2) {
        return 1;
    }

    return solution(number - 1) + solution(number - 2);
}

void print(const int number) {
    cout << number << endl;
}

// 0 - 1
// 1 - 1
// 2 - 2
// 3 - 3
// 4 - 5
// 5 - 8
// 6 - 13

int main() {
    int number;
    cin >> number;

    print(solution(number));
}
