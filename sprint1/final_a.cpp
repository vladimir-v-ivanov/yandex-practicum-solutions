// Финальная задача A спринта 1. Ближайший ноль

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(const int len, vector<int>& numbers) {
    int counter = -1;

    for (int i = 0; i < len; i++) {
        if (numbers[i] == 0) {
            counter = 0;

            continue;
        }

        if (counter < 0) {
            continue;
        }

        counter++;

        if (numbers[i] > counter) {
            numbers[i] = counter;
        }
    }

    counter = -1;

    for (int i = len - 1; i >= 0; i--) {
        if (numbers[i] == 0) {
            counter = 0;

            continue;
        }

        if (counter < 0) {
            continue;
        }

        counter++;

        if (numbers[i] > counter) {
            numbers[i] = counter;
        }
    }

    return numbers;
}

void print(const vector<int>& numbers) {
    for (const int number : numbers) {
        cout << number << " ";
    }

    cout << endl;
}

int main() {
    int len, num;
    cin >> len;

    vector<int> numbers(len);

    for (int i = 0; i < len; i++) {
        cin >> num;
        numbers[i] = num > 0 ? len : 0;
    }

    print(solution(len, numbers));
}
