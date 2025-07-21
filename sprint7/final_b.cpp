#include <iostream>
#include <vector>

using namespace std;

void dp(vector<int>& nums, const int len, const int i) {

}

int main() {
    int len;
    cin >> len;

    vector<int> nums(len);
    int total = 0;

    for (int i = 0; i < len; i++) {
        cin >> nums[i];
        total += nums[i];
    }

    if (total % 2 != 0) {
        cout << "False" << endl;
        return 0;
    }

    vector dp(total / 2, false);

    for (int i = 0; i < len; i++) {

    }
}
