// Задача H спринта 3. Большое число

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool compare(const string& a, const string& b) {
    const int num1 = stoi(a + b);
    const int num2 = stoi(b + a);

    if (num1 == num2) {
        if (stoi(b) < stoi(a)) {
            return true;
        }
    }

    return num1 > num2;
}

vector<string>& solution(const int len, vector<string>& nums) {
    sort(nums.begin(), nums.end(), compare);

    return nums;
}

void print(const vector<string>& nums) {
    for (const string& num : nums) {
        cout << num;
    }
}

int main() {
    int len;
    cin >> len;
    vector<string> nums;
    string num;
    nums.reserve(len);

    for (int i = 0; i < len; i++) {
        cin >> num;
        nums.push_back(num);
    }

    print(solution(len, nums));
}
