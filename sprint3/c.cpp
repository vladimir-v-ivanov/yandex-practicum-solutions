// Задача C спринта 3. Подпоследовательность

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>

using namespace std;

bool solution(const string& line1, const string& line2) {
    const unsigned long len1 = line1.length();
    const unsigned long len2 = line2.length();
    unsigned long i, j;

    for (i = 0, j = 0; j < len2; j++) {
        if (line1[i] == line2[j]) {
            i++;
        }
    }

    return i == len1;
}

void print(const bool is_subsequence) {
    cout << (is_subsequence ? "True" : "False") << endl;
}

int main() {
    string line1, line2;

    getline(cin, line1);
    getline(cin, line2);

    print(solution(line1, line2));
}
