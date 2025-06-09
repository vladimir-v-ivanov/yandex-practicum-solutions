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
#include <optional>


using namespace std;

optional<int> get_value(const Node* node) {
    if (node == nullptr) {
        return nullopt;
    }

    return node->value;
}

bool is_anagram(const Node* root1, const Node* root2) {
    if (get_value(root1->left) != get_value(root2->right)) {
        return false;
    }

    if (get_value(root1->right) != get_value(root2->left)) {
        return false;
    }

    bool first = true;
    bool second = true;

    if (root1->left != nullptr && root2->right != nullptr) {
        first = is_anagram(root1->left, root2->right);
    }

    if (root1->right != nullptr && root2->left != nullptr) {
        second = is_anagram(root1->right, root2->left);
    }

    return first && second;
}

bool Solution(const Node* root) {
    if (get_value(root->left) != get_value(root->right)) {
        return false;
    }

    bool result = true;

    if (root->left != nullptr && root->right != nullptr) {
        result = is_anagram(root->left, root->right);
    }

    return result;
}

#ifndef REMOTE_JUDGE
void test() {
    Node node1({3, nullptr, nullptr});
    Node node2({4, nullptr, nullptr});
    Node node3({4, nullptr, nullptr});
    Node node4({3, nullptr, nullptr});
    Node node5({2, &node1, &node2});
    Node node6({2, &node3, &node4});
    Node node7({1, &node5, &node6});
    assert(Solution(&node7));
}


int main() {
    test();
}
#endif
