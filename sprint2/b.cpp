// Задача B спринта 2. Список дел

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>
#include <string>
#include <utility>

using namespace std;

#ifndef REMOTE_JUDGE

struct Node {
    string value;
    Node* next;
    Node(string value, Node* next) : value(std::move(value)), next(next) {}
};

#endif

void solution(Node* head) {
    while (head != nullptr) {
        cout << head->value << endl;
        head = head->next;
    }
}
