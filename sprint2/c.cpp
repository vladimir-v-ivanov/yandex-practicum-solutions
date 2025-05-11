// Задача C спринта 2. Нелюбимое дело

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>
#include <string>

using namespace std;

#ifndef REMOTE_JUDGE

struct Node {
    string value;
    Node* next;
    Node(string value, Node* next) : value(move(value)), next(next) {}
};

#endif

Node* solution(Node* head, int idx) {
    if (idx == 0) {
        Node* next = head->next;
        return next;
    }

    Node* current = head;
    Node* previous = head;

    while (idx > 0 && current != nullptr) {
        previous = current;
        current = current->next;
        idx--;
    }

    if (current != nullptr) {
        previous->next = current->next;
    }

    return head;
}
