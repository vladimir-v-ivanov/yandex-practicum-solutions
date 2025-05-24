// Пробная задача D. Две фишки

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int len, k;
    vector<int> nums;

    cin >> len;

    for (int i = 0; i < len; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    cin >> k;

    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (nums[i] + nums[j] == k) {
                cout << nums[i] << " " << nums[j] << endl;
                return 0;
            }
        }
    }

    cout << "None" << endl;
}
