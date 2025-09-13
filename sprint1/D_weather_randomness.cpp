// Задача D спринта 1. Хаотичность погоды

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int solution(const int total_days, const vector<int>& days) {
    int chaoticness = 0;

    if (total_days == 0) {
        return 0;
    }

    if (total_days == 1) {
        return 1;
    }

    if (days[0] > days[1]) {
        ++chaoticness;
    }

    for (int i = 1; i < total_days - 1; ++i) {
        if (days[i - 1] < days[i] && days[i] > days[i + 1]) {
            ++chaoticness;
        }
    }

    if (days[total_days - 1] > days[total_days - 2]) {
        chaoticness++;
    }

    return chaoticness;
}

void print(const int chaoticness) {
    cout << chaoticness << endl;
}

int main() {
    string line;

    getline(cin, line);
    const int total_days = stoi(line);

    vector<int> days(total_days);
    getline(cin, line);
    istringstream iss(line);

    for (int i = 0; i < total_days; ++i) {
        iss >> days[i];
    }

    print(solution(total_days, days));
}
