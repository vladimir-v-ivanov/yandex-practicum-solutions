#include <optional>
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
#include <cmath>
#include <iostream>
#include <cassert>

using namespace std;

optional<int> get_value(const Node* node) {
    if (node == nullptr) {
        return nullopt;
    }

    return node->value;
}

bool Solution(const Node* root1, const Node* root2) {
    if (get_value(root1) != get_value(root2)) {
        return false;
    }

    if (get_value(root1->left) != get_value(root2->left)) {
        return false;
    }

    if (get_value(root1->right) != get_value(root2->right)) {
        return false;
    }

    bool left = true;
    bool right = true;

    if (root1->left != nullptr) {
        left = Solution(root1->left, root2->left);
    }

    if (root1->right != nullptr) {
        right = Solution(root1->right, root2->right);
    }

    return left && right;
}

#ifndef REMOTE_JUDGE
void test() {

    Node node1({1, nullptr, nullptr});
    Node node2({2, nullptr, nullptr});
    Node node3({3, &node1, &node2});

    Node node4({1, nullptr, nullptr});
    Node node5({2, nullptr, nullptr});
    Node node6({3, &node4, &node5});
    assert(Solution(&node3, &node6));
}

int main() {
    test();
}
#endif
