#include <iostream>
#include <vector>

using namespace std;

int main() {
    string line;
    getline(cin, line);

    const int len = static_cast<int>(line.length());
    vector pi(len, 0);

    for (int i = 1; i < len; i++) {
        int k = pi[i - 1];

        while (k > 0 && line[k] != line[i]) {
            k = pi[k - 1];
        }

        if (line[k] == line[i]) {
            k++;
        }

        pi[i] = k;
    }

    for (int i = 0; i < len; i++) {
        cout << pi[i] << " ";
    }

    cout << endl;
}
