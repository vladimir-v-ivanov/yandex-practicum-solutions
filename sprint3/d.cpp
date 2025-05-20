// Задача D спринта 3. Печеньки

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>
#include <vector>

using namespace std;

int solution(const vector<int>& kids, const vector<int>& cookies, const int max1, const int max2) {
    vector kids_sizes(max1 + 1,0);

    for (const int kid : kids) {
        kids_sizes[kid]++;
    }

    vector cookies_sizes(max2 + 1,0);

    for (const int cookie : cookies) {
        cookies_sizes[cookie]++;
    }

    int result = 0;
    int i = 0, j = 0;

    while (i < kids_sizes.size() && j < cookies_sizes.size()) {
        if (kids_sizes[i] == 0) {
            i++;
            continue;
        }

        if (cookies_sizes[j] == 0) {
            j++;
            continue;
        }

        if (i <= j) {
            kids_sizes[i]--;
            cookies_sizes[j]--;
            result++;
        } else {
            j++;
        }
    }

    return result;
}

void print(const int num) {
    cout << num << endl;
}

int main() {
    int len, num, max1 = 0, max2 = 0;
    vector<int> kids, cookies;

    cin >> len;
    kids.reserve(len);

    for (int i = 0; i < len; i++) {
        cin >> num;

        if (num > max1) {
            max1 = num;
        }

        kids.push_back(num);
    }

    cin >> len;

    for (int i = 0; i < len; i++) {
        cin >> num;

        if (num > max2) {
            max2 = num;
        }

        cookies.push_back(num);
    }

    print(solution(kids, cookies, max1, max2));
}
