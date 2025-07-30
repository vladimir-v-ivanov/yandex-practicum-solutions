#include <iostream>
#include <string>

using namespace std;

struct Node {
    string chunk;
    int weight;
    Node* left;
    Node* right;
    Node* parent;
};

Node* find(Node* node, const int k) {
    if (node == nullptr) {
        return nullptr;
    }

    if (node->left == nullptr && node->right == nullptr) {
        return node;
    }

    if (node->left != nullptr && node->left->weight > k) {
        return find(node->left, k);
    }

    return find(node->right, k);
}

Node* merge(Node* left, Node* right) {
    const auto result = new Node("", left->weight + right->weight, left, right, nullptr);
    left->parent      = result;
    right->parent     = result;

    return result;
}

Node* split(Node* node, const int index) {}

void print(Node* node) {}

void pull(Node* node) {
    if (node == nullptr) {
        return;
    }

    node->weight = node->left->weight + node->right->weight;

    pull(node->parent);
}

int main() {}
