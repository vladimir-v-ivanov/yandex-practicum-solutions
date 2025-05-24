// Пробная задача D. Две фишки - 2

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int len, k;
    vector<int> nums;
    unordered_map<int, int> map;

    cin >> len;

    for (int i = 0; i < len; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    cin >> k;

    for (int i = 0; i < len; i++) {
        if (const int y = k - nums[i]; map.find(y) != map.end()) {
            cout << map[y] << " " << nums[i] << endl;
            return 0;
        }

        map[nums[i]] = nums[i];
    }

    cout << "None" << endl;
}
