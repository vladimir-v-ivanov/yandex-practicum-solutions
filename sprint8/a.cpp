#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string word;
    vector<string> words;

    while (cin >> word) {
        words.push_back(word);

        if (const int c = std::cin.peek(); c == '\n' || c == EOF) {
            break;
        }
    }

    int i = 0, j = static_cast<int>(words.size()) - 1;

    while (i < j) {
        swap(words[i], words[j]);
        i++;
        j--;
    }

    for (i = 0; i < static_cast<int>(words.size()); i++) {
        cout << words[i] << " ";
    }

    cout << endl;
}
