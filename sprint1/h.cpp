// Задача H спринта 1. Двоичная система

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>
#include <vector>

using namespace std;

vector<int>& solution(const string& number1, const string& number2) {
    unsigned long len1   = number1.length();
    unsigned long len2   = number2.length();
    auto*         result = new vector<int>;

    int remainder = 0;

    while (len1 > 0 || len2 > 0) {
        const int bit1 = len1 > 0 ? number1[len1 - 1] - '0' : 0;
        const int bit2 = len2 > 0 ? number2[len2 - 1] - '0' : 0;
        const int sum  = bit1 + bit2 + remainder;

        result->push_back(sum % 2);
        remainder = sum / 2;

        if (len1 > 0) {
            len1--;
        }

        if (len2 > 0) {
            len2--;
        }
    }

    if (remainder) {
        result->push_back(remainder);
    }

    return *result;
}

void print(const vector<int>& result) {
    for (unsigned long i = result.size(); i > 0; i--) {
        cout << result[i - 1];
    }

    cout << endl;
}

int main() {
    string number1;
    string number2;

    getline(cin, number1);
    getline(cin, number2);

    print(solution(number1, number2));
}
