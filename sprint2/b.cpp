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
    string chunk;
    Node* next;
    Node(string value, Node* next) : chunk(std::move(value)), next(next) {}
};

#endif

void solution(Node* head) {
    while (head != nullptr) {
        cout << head->chunk << endl;
        head = head->next;
    }
}
