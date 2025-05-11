// Задача D спринта 2. Заботливая мама

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <string>
#include <utility>

using namespace std;

#ifndef REMOTE_JUDGE

struct Node {
    string value;
    Node* next;
    Node(string value, Node* next) : value(move(value)), next(next) {}
};

#endif

int solution(Node* head, const string& elem) {
    int idx = 0;

    while (head != nullptr) {
        if (head->value == elem) {
            return idx;
        }

        head = head->next;
        idx++;
    }

    return -1;
}
