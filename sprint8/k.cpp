#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

unordered_set even{'b', 'd', 'f', 'h', 'j', 'l', 'n', 'p', 'r', 't', 'v', 'x', 'z'};

int main() {
    string line1, line2;
    getline(cin, line1);
    getline(cin, line2);

    int i = 0, j = 0;

    while (i < line1.size() && j < line2.size()) {
        if (!even.contains(line1[i])) {
            i++;
            continue;
        }

        if (!even.contains(line2[j])) {
            j++;
            continue;
        }

        if (line1[i] < line2[j]) {
            cout << "-1" << endl;
            return 0;
        }

        if (line1[i] > line2[j]) {
            cout << "1" << endl;
            return 0;
        }

        i++;
        j++;
    }

    while (i < line1.size()) {
        if (even.contains(line1[i])) {
            cout << "1" << endl;
            return 0;
        }

        i++;
    }

    while (j < line2.size()) {
        if (even.contains(line2[j])) {
            cout << "-1" << endl;
            return 0;
        }

        j++;
    }

    cout << "0" << endl;
}
