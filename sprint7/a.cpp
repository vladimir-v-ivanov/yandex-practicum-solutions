#include <iostream>
#include <vector>

using namespace std;

int main() {
    int days_num;
    cin >> days_num;

    if (days_num < 2) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> prices(days_num);
    for (int i = 0; i < days_num; i++) {
        cin >> prices[i];
    }

    int bought = 0;
    int total  = 0;

    for (int i = 1; i < days_num; i++) {
        if (prices[bought] < prices[i]) {
            total += prices[i] - prices[bought];
            bought = i;
        } else {
            bought = i;
        }
    }

    cout << total << endl;
}
