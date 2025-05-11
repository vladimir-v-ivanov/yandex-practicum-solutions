// Задача I спринта 2. Ограниченная очередь

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>
#include <sstream>

using namespace std;

int main() {
    string line;

    getline(cin, line);
    const int commands = stoi(line);

    getline(cin, line);
    const int max_size = stoi(line);
    int       size     = 0;
    int       queue[max_size];
    int       head = 0;
    int       tail = 0;

    for (int i = 0; i < commands; i++) {
        getline(cin, line);
        istringstream iss(line);

        string word;
        iss >> word;

        if (word == "push") {
            if (size == max_size) {
                cout << "error\n";
                continue;
            }

            iss >> word;
            queue[tail] = stoi(word);
            tail        = (tail + 1) % max_size;
            size++;
        }

        if (word == "pop") {
            if (size == 0) {
                cout << "None\n";
                continue;
            }

            cout << queue[head] << "\n";
            head = (head + 1) % max_size;
            size--;
        }

        if (word == "peek") {
            if (size == 0) {
                cout << "None\n";
                continue;
            }

            cout << queue[head] << "\n";
        }

        if (word == "size") {
            cout << size << "\n";
        }
    }
}
