// Задача F спринта 3. Периметр треугольника

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int>& edges) {
    unsigned long i = edges.size() - 1;

    ranges::sort(edges);

    while (edges[i] >= edges[i - 1] + edges[i - 2]) {
        i--;
    }

    return edges[i] + edges[i - 1] + edges[i - 2];
}

void print(const int num) {
    cout << num << endl;
}

int main() {
    int len, num;
    vector<int> edges;

    cin >> len;
    edges.reserve(len);

    for (int i = 0; i < len; i++) {
        cin >> num;
        edges.push_back(num);
    }

    print(solution(edges));
}
