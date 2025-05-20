// Задача J спринта 3. Пузырек

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int>& nums) {
    for (const int num : nums) {
        cout << num << " ";
    }

    cout << "\n";
}

void solution(const int len, vector<int> nums) {
    bool is_sorted = false;

    for (int i = 0; i < len - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < len - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
                swapped = true;
                is_sorted = true;
            }
        }

        if (!swapped) {
            break;
        }

        print(nums);
    }

    if (!is_sorted) {
        print(nums);
    }
}

int main() {
    int len, num;
    cin >> len;
    vector<int> nums;
    nums.reserve(len);

    for (int i = 0; i < len; i++) {
        cin >> num;
        nums.push_back(num);
    }

    solution(len, nums);
}
