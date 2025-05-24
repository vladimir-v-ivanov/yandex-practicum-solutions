// Задача K спринта 4. Ближайшая остановка

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int get_cell_offset(const int x) {
    return x >= 0 ? x / 20 : (x - 20 + 1) / 20;
}

long long get_cell(const int x, const int y) {
    return static_cast<long long>(x) << 32 | y & 0xffffffff;
}

int main() {
    int n, m;
    vector<pair<int, int>> subway;
    unordered_map<long long, vector<pair<int, int>>> bus;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        subway.emplace_back(x, y);
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        const int cx = get_cell_offset(x);
        const int cy = get_cell_offset(y);
        bus[get_cell(cx, cy)].emplace_back(x, y);
    }

    int longest_index = -1;
    int longest_amount = 0;
    vector counts(n, 0);

    for (int i = 0; i < n; i++) {
        const int x1 = subway[i].first;
        const int y1 = subway[i].second;
        const int cx = get_cell_offset(x1);
        const int cy = get_cell_offset(y1);

        for (int j = -1; j <= 1; j++) {
            for (int k = -1; k <= 1; k++) {
                const long long cell = get_cell(cx + j, cy + k);

                if (bus.contains(cell)) {
                    for (auto [x2   , y2] : bus[cell]) {
                        if (sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) <= 20) {
                            counts[i]++;
                        }
                    }
                }
            }
        }

        if (counts[i] > longest_amount) {
            longest_amount = counts[i];
            longest_index = i;
        }
    }

    cout << longest_index + 1 << endl;
}
