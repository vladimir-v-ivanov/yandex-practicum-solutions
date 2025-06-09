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

using namespace std;

bool Solution(const Node* root) {
    if (root->left != nullptr) {
        if (
            root->left->value >= root->value
            || (root->left->right != nullptr && root->left->right->value >= root->value)
            || !Solution(root->left)
        ) {
            return false;
        }
    }

    if (root->right != nullptr) {
        if (
            root->right->value <= root->value
            || !Solution(root->right)
        ) {
            return false;
        }
    }

    return true;
}


#ifndef REMOTE_JUDGE
void test() {
    {
        Node node1({1, nullptr, nullptr});
        Node node2({4, nullptr, nullptr});
        Node node3({3, &node1, &node2});
        Node node4({8, nullptr, nullptr});
        Node node5({5, &node3, &node4});
        assert(Solution(&node5));
    }
    {
        Node node1({1, nullptr, nullptr});
        Node node2({5, nullptr, nullptr});
        Node node3({3, &node1, &node2});
        Node node4({8, nullptr, nullptr});
        Node node5({5, &node3, &node4});
        assert(!Solution(&node5));
    }
    {
        Node node3({2, nullptr, nullptr});
        Node node4({6, nullptr, nullptr});
        Node node5({4, nullptr, nullptr});
        Node node6({8, nullptr, nullptr});
        Node node1({4, &node3, &node4});
        Node node2({6, &node5, &node6});
        Node node0({5, &node1, &node2});
        assert(!Solution(&node0));
    }
}


int main() {
    test();
}
#endif
