#ifndef REMOTE_JUDGE
struct Node {
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(const int value, Node* left, Node* right) : value(value), left(left), right(right) {}
};
#endif

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif
#include <cassert>
#include <cmath>

Node* insert(Node* root, int key) {
    if (key < root->value) {
        if (root->left == nullptr) {
            root->left = new Node(key, nullptr, nullptr);
        } else {
            root->left = insert(root->left, key);
        }
    } else {
        if (root->right == nullptr) {
            root->right = new Node(key, nullptr, nullptr);
        } else {
            root->right = insert(root->right, key);
        }
    }

    return root;
}

#ifndef REMOTE_JUDGE
void test() {
    Node node1(7, nullptr, nullptr);
    Node node2(8, &node1, nullptr);
    Node node3(7, nullptr, &node2);
    Node* newHead = insert(&node3, 6);
    assert(newHead->left->value == 6);
    assert(newHead == &node3);
}

int main() {
    test();
}
#endif
