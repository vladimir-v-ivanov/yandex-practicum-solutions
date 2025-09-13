/*
Sprint 1. Task A. Function Value.

Problem:
Implement a function that calculates the value of an expression using the formula: a * x^2 + b * x + c.

Input Format:
Integers a, x, b, c separated by a single space.

Output Format:
Integer result of the expression.

Input Example:
-8 -5 -2 7

Output Example:
-183

Time complexity: O(1)
Space complexity: O(1)
*/

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif // REMOTE_JUDGE

#include <iostream>

int solution(const int a, const int x, const int b, const int c) {
    return a * (x * x) + b * x + c;
}

void print(const int result) {
    std::cout << result << std::endl;
}

int main() {
    int a, x, b, c;
    std::cin >> a >> x >> b >> c;

    print(solution(a, x, b, c));
}
