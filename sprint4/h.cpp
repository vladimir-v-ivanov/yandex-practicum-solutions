// Задача H спринта 4. Подстроки

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    string                   line;
    unordered_map<char, int> chars;
    int                      begin = 0, longest = 0;

    getline(cin, line);
    int i;

    for (i = 0; i < line.size(); i++) {
        if (!chars.contains(line[i]) || chars[line[i]] < begin) {
            chars[line[i]] = i;
            continue;
        }

        longest        = max(longest, i - begin);
        begin          = chars[line[i]] + 1;
        chars[line[i]] = i;
    }

    longest = max(longest, i - begin);

    cout << longest << endl;
}
