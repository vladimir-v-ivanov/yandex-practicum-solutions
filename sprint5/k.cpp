#ifndef REMOTE_JUDGE
struct Node {
    int value;
    const Node* left = nullptr;
    const Node* right = nullptr;
    Node(const Node* left, const Node* right, const int value) : value(value), left(left), right(right) {}
};
#endif

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>

using namespace std;

void print_range(Node* root, const int l, const int r) {
    if (root->value >= l && root->left != nullptr) {
        print_range(const_cast<Node*>(root->left), l, r);
    }

    if (root->value >= l && root->value <= r) {
        cout << root->value << "\n";
    }

    if (root->value <= r && root->right != nullptr) {
        print_range(const_cast<Node*>(root->right), l, r);
    }
}

#ifndef REMOTE_JUDGE
void test() {
    Node node1({nullptr, nullptr, 2});
    Node node2({nullptr, &node1, 1});
    Node node3({nullptr, nullptr, 8});
    Node node4({nullptr, &node3, 8});
    Node node5({&node4, nullptr, 9});
    Node node6({&node5, nullptr, 10});
    Node node7({&node2, &node6, 5});
    print_range(&node7, 2, 8);
    // expected output: 2 5 8 8
}

int main() {
    test();
}
#endif
