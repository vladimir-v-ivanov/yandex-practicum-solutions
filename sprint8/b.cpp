#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string line1, line2;
    getline(cin, line1);
    getline(cin, line2);

    int i = 0, j = 0, diff = 0;

    while (i < line1.size() && j < line2.size()) {
        if (line1[i] != line2[j]) {
            if (line1[i] == line2[j + 1]) {
                j++;
                diff++;
                continue;
            } if (line1[i + 1] == line2[j]) {
                i++;
                diff++;
                continue;
            }

            diff++;
        }

        i++;
        j++;
    }

    if (i < line1.size()) {
        diff++;
    }

    if (j < line2.size()) {
        diff++;
    }

    if (diff > 1) {
        cout << "FAIL" << endl;
    } else {
        cout << "OK" << endl;
    }
}
