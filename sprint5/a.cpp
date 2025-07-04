#ifndef REMOTE_JUDGE
struct Node {
    int         value;
    const Node* left  = nullptr;
    const Node* right = nullptr;

    Node(int value, Node* left, Node* right) : value(value), left(left), right(right) {
    }
};
#endif

#ifdef REMOTE_JUDGE
#include "solution_tree.h"
#endif

#include <cassert>
#include <climits>
#include <iostream>

using namespace std;

int Solution(const Node* root) {
    if (root == nullptr) {
        return INT_MIN;
    }

    const int left  = Solution(root->left);
    const int right = Solution(root->right);

    return max(left, max(right, root->value));
}

#ifndef REMOTE_JUDGE
void test() {
    Node node1({1, nullptr, nullptr});
    Node node2({-5, nullptr, nullptr});
    Node node3({3, &node1, &node2});
    Node node4({2, &node3, nullptr});
    assert(Solution(&node4) == 3);
}

int main() {
    test();
}
#endif
