// Задача E спринта 2. Все наоборот

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <string>
#include <utility>

using namespace std;

#ifndef REMOTE_JUDGE

struct Node {
    Node(string value, Node* next, Node* prev): chunk(move(value)), next(next), prev(prev) {
    }

    string chunk;
    Node*  next;
    Node*  prev;
};

#endif

Node* solution(Node* head) {
    if (head->next == nullptr) {
        return head;
    }

    Node* current = head;
    Node* prev    = head;

    while (current != nullptr) {
        prev          = current->prev;
        current->prev = current->next;
        current->next = prev;
        current       = current->prev;
    }

    return prev->prev;
}
