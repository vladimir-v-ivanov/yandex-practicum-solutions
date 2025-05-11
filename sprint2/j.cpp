// Задача J спринта 2. Списочная очередь

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>
#include <sstream>

using namespace std;

struct Node {
    Node(int value, Node* next) : value(value), next(next) {}

    int value;
    Node* next;
};

int main() {
    string line;

    getline(cin, line);
    const int commands = stoi(line);
    int size = 0;
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < commands; i++) {
        getline(cin, line);
        istringstream iss(line);

        string word;
        iss >> word;

        if (word == "put") {
            iss >> word;
            Node* node = new Node(stoi(word), nullptr);

            if (size == 0) {
                head = node;
                tail = node;
            } else {
                tail->next = node;
                tail = node;
            }

            size++;
        }

        if (word == "get") {
            if (size == 0) {
                cout << "error\n";
                continue;
            }

            cout << head->value << "\n";

            Node* prev = head;
            head = head->next;

            if (head == nullptr) {
                tail = nullptr;
            }

            delete prev;
            size--;
        }

        if (word == "size") {
            cout << size << "\n";
        }
    }

    while (head != nullptr) {
        Node* prev = head->next;
        delete head;
        head = prev;
    }
}
