#ifndef REMOTE_JUDGE
struct Node {
    Node* left;
    Node* right;
    int value;
    int size;
};
#endif

#ifdef REMOTE_JUDGE
#include "solution.h"
#endif
#include <cassert>
#include <utility>

using namespace std;

int getSize(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->size;
}

pair<Node*, Node*> split(Node* root, int k) {
    if (root->size - getSize(root->right) == k) {
        Node* right = root->right;
        root->right = nullptr;
        root->size -= getSize(right);

        return make_pair(root, right);
    }

    if (getSize(root->left) == k) {
        Node* left = root->left;
        root->left = nullptr;
        root->size -= getSize(left);

        return make_pair(left, root);
    }

    if (getSize(root->left) < k - 1) {
        pair<Node*, Node*> nodes = split(root->right, k - getSize(root->left) - 1);
        root->size -= getSize(nodes.second);
        root->right = nodes.first;

        return make_pair(root, nodes.second);
    }

    pair<Node*, Node*> nodes = split(root->left, k);
    root->size -= getSize(nodes.first);
    root->left = nodes.second;

    return make_pair(nodes.first, root);
}

#ifndef REMOTE_JUDGE
void test() {
    {
        Node node5  = {nullptr, nullptr, 130, 1};
        Node node7  = {nullptr, nullptr, 442, 1};
        Node node6  = {nullptr, &node7, 302, 2};
        Node node4  = {&node5, &node6, 220, 4};
        Node node10 = {nullptr, nullptr, 858, 1};
        Node node9  = {nullptr, nullptr, 701, 1};
        Node node8  = {&node9, &node10, 763, 3};
        Node node3  = {&node4, &node8, 545, 8};
        Node node2  = {nullptr, &node3, 31, 9};
        Node node1  = {&node2, nullptr, 867, 10};  // корень



        pair<Node*, Node*> res = split(&node1, 7);
        assert(res.first->size == 10);
        assert(res.second->size == 5);
    }
}


int main() {
    test();
}
#endif
