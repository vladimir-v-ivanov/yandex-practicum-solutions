#include <limits.h>
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
#include <cmath>
#include <iostream>

using namespace std;

int max_sum = INT_MIN;

int dfs(const Node* root) {
    if (root == nullptr) {
        return 0;
    }

    const int left_sum  = max(0, dfs(root->left));
    const int right_sum = max(0, dfs(root->right));

    max_sum = max(max_sum, root->value + left_sum + right_sum);

    return root->value + max(left_sum, right_sum);
}

int Solution(const Node* root) {
    max_sum = INT_MIN;
    dfs(root);
    return max_sum;
}

#ifndef REMOTE_JUDGE
void test() {
    {
        Node node1({5, nullptr, nullptr});
        Node node2({1, nullptr, nullptr});
        Node node3({-3, &node2, &node1});
        Node node4({2, nullptr, nullptr});
        Node node5({2, &node4, &node3});
        assert(Solution(&node5) == 6);
    }
}

int main() {
    test();
}
#endif
