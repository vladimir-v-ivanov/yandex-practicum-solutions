// Задача C спринта 3. Гардероб

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int>& nums) {
    int left = 0, mid = 0, right = nums.size() - 1;

    while (mid <= right) {
        if (nums[mid] == 1) {
            mid++;
        } else if (nums[mid] == 0) {
            swap(nums[left], nums[mid]);
            mid++;
            left++;
        } else {
            swap(nums[right], nums[mid]);
            right--;
        }
    }

    return nums;
}

void print(const vector<int>& nums) {
    for (const int num : nums) {
        cout << num << " ";
    }
}

int main() {
    int len, num;
    vector<int> nums;

    cin >> len;
    nums.reserve(len);

    for (int i = 0; i < len; i++) {
        cin >> num;
        nums.push_back(num);
    }

    print(solution(nums));
}
