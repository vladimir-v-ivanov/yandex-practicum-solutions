#ifndef REMOTE_JUDGE
struct Node {
    int value;
    const Node* left = nullptr;
    const Node* right = nullptr;
    Node(int value, Node* left, Node* right) : value(value), left(left), right(right) {}
};
#endif

#ifdef REMOTE_JUDGE
#include "solution_tree.h"
#endif
#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

void calculate(const Node* root, int current, int& total) {
    current += root->value;

    if (root->left != nullptr) {
        calculate(root->left, current * 10, total);
    }

    if (root->right != nullptr) {
        calculate(root->right, current * 10, total);
    }

    if (root->left == nullptr && root->right == nullptr) {
        total += current;
    }
}

int Solution(const Node* root) {
    int total = 0;

    calculate(root, 0, total);

    return total;
}

#ifndef REMOTE_JUDGE
void test() {
    Node node1({2, nullptr, nullptr});
    Node node2({1, nullptr, nullptr});
    Node node3({3, &node1, &node2});
    Node node4({2, nullptr, nullptr});
    Node node5({1, &node4, &node3});
    assert(Solution(&node5) == 275);
}

int main() {
    test();
}
#endif
