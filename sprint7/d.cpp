#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num;
    cin >> num;

    vector<long long> dp(num + 1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= num; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
    }

    cout << dp[num] << endl;
}
