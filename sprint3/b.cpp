// Задача B спринта 3. Комбинации

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<vector<char>> keys = {
    {'a', 'b', 'c'},
    {'d', 'e', 'f'},
    {'g', 'h', 'i'},
    {'j', 'k', 'l'},
    {'m', 'n', 'o'},
    {'p', 'q', 'r', 's'},
    {'t', 'u', 'v'},
    {'w', 'x', 'y', 'z'}
};

void solution(const vector<int>& nums, const string& result) {
    if (nums.empty()) {
        cout << result << " ";
        return;
    }

    const vector sliced(nums.begin() + 1, nums.end());

    for (const char i : keys[nums[0]]) {
        solution(sliced, result + i);
    }
}

void print(const string& result) {
    cout << result << endl;
}

int main() {
    vector<int> nums;
    string numbers;
    getline(cin, numbers);

    for (const char number : numbers) {
        nums.push_back(number - '0' - 2);
    }

    solution(nums, "");
}
