#include <iostream>
#include <vector>

using namespace std;

int main() {
    int len;
    cin >> len;

    vector<int> nums(len);

    for (int i = 0; i < len; i++) {
        cin >> nums[i];
    }

    cin >> len;

    vector<int> pattern(len);

    for (int i = 0; i < len; i++) {
        cin >> pattern[i];
    }

    int delta = 0;

    vector<int> matches;

    for (int i = 0; i < nums.size(); i++) {
        bool match = true;

        for (int j = 0; j < pattern.size(); j++) {
            if (j == 0) {
                delta = nums[i + j] - pattern[j];
                continue;
            }

            if (nums[i + j] - pattern[j] != delta) {
                match = false;
                break;
            }
        }

        if (match) {
            matches.push_back(i + 1);
        }
    }

    for (const int match : matches) {
        cout << match << " ";
    }

    cout << endl;
}
