// Финальная задача B спринта 1. Ловкость рук

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>
#include <vector>

using namespace std;

int solution(const int max, const vector<int>& numbers) {
    int wins = 0;

    for (int i = 1; i <= 9; i++) {
        if (numbers[i] > 0 && numbers[i] <= max) {
            wins++;
        }
    }

    return wins;
}

void print(const int wins) {
    cout << wins << endl;
}

int main() {
    string line;
    vector numbers(10, 0);

    getline(cin, line);
    const int k = stoi(line);

    for (int i = 0; i < 4; i++) {
        getline(cin, line);

        for (int j = 0; j < 4; j++) {
            if (line[j] >= '1' && line[j] <= '9') {
                numbers[line[j] - '0']++;
            }
        }
    }

    print(solution(k * 2, numbers));
}
