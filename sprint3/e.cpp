// Задача E спринта 3. Покупка домов

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int>& edges, int budget) {
    int result = 0;

    ranges::sort(edges);

    for (const int price : edges) {
        if (price > budget) {
            break;
        }

        budget -= price;
        result++;
    }

    return result;
}

void print(const int num) {
    cout << num << endl;
}

int main() {
    int len, budget, num;
    vector<int> prices;

    cin >> len;
    cin >> budget;
    prices.reserve(len);

    for (int i = 0; i < len; i++) {
        cin >> num;
        prices.push_back(num);
    }

    print(solution(prices, budget));
}
