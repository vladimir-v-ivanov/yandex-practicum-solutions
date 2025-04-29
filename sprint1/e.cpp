// Задача E спринта 1. Самое длинное слово

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>
#include <sstream>
#include <tuple>

using namespace std;

tuple<int, int, const string> solution(const int len, const string& line) {
    int word_start = 0;
    int word_end = 0;
    int max_len = 0;
    int curr_start = 0;

    for (int i = 0; i <= len; ++i) {
        if (i == len || line[i] == ' ') {
            if (const int word_len = i - curr_start; word_len > max_len) {
                max_len = word_len;
                word_start = curr_start;
                word_end = i;
            }

            curr_start = i + 1;
        }
    }

    return make_tuple(word_start, word_end, line);
}

void print(const int start, const int end, const string& line) {
    for (int i = start; i < end; ++i) {
        cout << line[i];
    }

    cout << '\n' << end - start << endl;
}

int main() {
    string line;

    getline(cin, line);
    const int len = stoi(line);

    getline(cin, line);

    apply(print, solution(len, line));
}
