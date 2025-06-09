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

using namespace std;

bool Solution(const Node* root) {
    if (root->left != nullptr) {
        if (
            ((root->left->left != nullptr || root->left->right != nullptr) && root->right == nullptr)
            || !Solution(root->left)
        ) {
            return false;
        }
    }

    if (root->right != nullptr) {
        if (
            ((root->right->right != nullptr || root->right->left != nullptr) && root->left == nullptr)
            || !Solution(root->right)
        ) {
            return false;
        }
    }

    return true;
}


#ifndef REMOTE_JUDGE
void test() {
    Node node1({1, nullptr, nullptr});
    Node node2({-5, nullptr, nullptr});
    Node node3({3, &node1, &node2});
    Node node4({10, nullptr, nullptr});
    Node node5({2, &node3, &node4});
    assert(Solution(&node5));
}

int main() {
    test();
}
#endif
