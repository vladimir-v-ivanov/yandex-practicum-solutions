// Задача K спринта 1. Списочная формула

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<int>& solution(const string& number1, const string& number2) {
    auto*         result = new vector<int>;
    unsigned long len1   = number1.length();
    unsigned long len2   = number2.length();

    int remainder = 0;

    while (len1 > 0 || len2 > 0) {
        if (number1[len1 - 1] == ' ') {
            len1--;
            continue;
        }

        int num1 = len1 > 0 ? number1[len1 - 1] - '0' : 0;
        int num2 = len2 > 0 ? number2[len2 - 1] - '0' : 0;
        int sum  = num1 + num2 + remainder;

        result->push_back(sum % 10);
        remainder = sum / 10;

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
        cout << result[i - 1] << " ";
    }

    cout << endl;
}

int main() {
    string ignored;
    string number1;
    string number2;

    getline(cin, ignored);
    getline(cin, number1);
    getline(cin, number2);

    print(solution(number1, number2));
}
