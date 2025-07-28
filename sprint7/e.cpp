#include <climits>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int needed_sum;
    int bills_num;
    cin >> needed_sum >> bills_num;

    unordered_set<int> bills;

    for (int i = 0; i < bills_num; i++) {
        int bill;
        cin >> bill;
        bills.insert(bill);
    }

    vector dp(needed_sum + 1, INT_MAX / 2);
    dp[0] = 0;

    for (int i = 1; i <= needed_sum; i++) {
        for (const auto bill : bills) {
            if (i - bill >= 0) {
                dp[i] = min(dp[i], dp[i - bill] + 1);
            }
        }
    }

    cout << dp[needed_sum] << endl;
}
