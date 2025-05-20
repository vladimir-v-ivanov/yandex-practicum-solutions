// Задача A спринта 3. Генератор скобок

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>
#include <sstream>

using namespace std;

void solution(const int len, const string& str, const int opened, const int closed) {
    if (opened == len && closed == len) {
        cout << str << endl;
        return;
    }

    if (opened < len) {
        solution(len, str + "(", opened + 1, closed);
    }

    if (closed < opened) {
        solution(len, str + ")", opened, closed + 1);
    }
}

void print(const string& result) {
    cout << result << endl;
}

int main() {
    int len;
    cin >> len;
    string string;

    solution(len, "(", 1, 0);
}
