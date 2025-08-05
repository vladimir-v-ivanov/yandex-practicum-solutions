#include <iostream>
#include <vector>

using namespace std;

int main() {
    int needed_sum;
    cin >> needed_sum;
    int coins_num;
    cin >> coins_num;

    vector<int> coins(coins_num);
    for (int i = 0; i < coins_num; i++) {
        cin >> coins[i];
    }

    vector dp(needed_sum + 1, 0);
    dp[0] = 0;

    for (int i = 1; i <= needed_sum; i++) {
        for (const auto coin : coins) {
            if (i - coin >= 0) {
                dp[i] = max(dp[i], dp[i - coin] + 1);
            }
        }
    }

    cout << dp[needed_sum] << endl;
}
