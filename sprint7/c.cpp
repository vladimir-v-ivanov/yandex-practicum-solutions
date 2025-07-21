#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long capacity;
    cin >> capacity;
    int heap_num;
    cin >> heap_num;

    vector<pair<long long, long long>> heaps;

    for (int i = 0; i < heap_num; i++) {
        int cost, weight;
        cin >> cost >> weight;

        heaps.emplace_back(cost, weight);
    }

    ranges::sort(heaps, [](const auto& left, const auto& right) {
        return left.first > right.first;
    });

    long long max = 0;

    for (const auto& [cost, weight] : heaps) {
        if (cost == 0) {
            continue;
        }

        if (capacity == 0) {
            break;
        }

        const long long available = min(weight, capacity);

        max += available * cost;
        capacity -= available;
    }

    cout << max << endl;
}
