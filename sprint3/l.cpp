// Задача L спринта 3. Два велосипеда

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int solution(const int cost, int left, int right, const vector<int>& sums) {
    if (left >= right) {
        return -2;
    }

    while (left < right) {
        if (const int mid = (left + right) / 2; sums[mid] >= cost) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    if (left < sums.size()) {
        return left;
    }

    return -2;
}

void print(const int first, const int second) {
    cout << first << " " << second << endl;
}

int main() {
    string line;

    getline(cin, line);
    const int days_count = stoi(line);

    getline(cin, line);
    istringstream iss(line);
    vector sums(days_count, 0);

    for (int i = 0; i < days_count; i++) {
        iss >> sums[i];
    }

    getline(cin, line);
    const int cost = stoi(line);

    print(
        solution(cost, 0, days_count, sums) + 1,
        solution(cost * 2, 0, days_count, sums) + 1
    );
}
