// Финальная задача A спринта 2. Дек

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string line;

    getline(cin, line);
    const int commands = stoi(line);
    getline(cin, line);
    const int max_size = stoi(line);

    vector data(max_size, 0);
    int    size = 0;
    int    head = 0;
    int    tail = 0;

    for (int i = 0; i < commands; ++i) {
        getline(cin, line);
        istringstream iss(line);
        string        word;

        iss >> word;

        if (word == "push_back") {
            if (size == max_size) {
                cout << "error\n";
                continue;
            }

            iss >> word;
            data[tail] = stoi(word);
            tail       = (tail + 1) % max_size;
            size++;
        }
        else if (word == "push_front") {
            if (size == max_size) {
                cout << "error\n";
                continue;
            }

            iss >> word;
            head       = (head - 1 + max_size) % max_size;
            data[head] = stoi(word);
            size++;
        }
        else if (word == "pop_back") {
            if (size == 0) {
                cout << "error\n";
                continue;
            }

            tail = (tail - 1 + max_size) % max_size;
            cout << data[tail] << "\n";
            size--;
        }
        else if (word == "pop_front") {
            if (size == 0) {
                cout << "error\n";
                continue;
            }

            cout << data[head] << "\n";
            head = (head + 1) % max_size;
            size--;
        }
    }
}
