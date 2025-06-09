/*

Отчет: https://contest.yandex.ru/contest/24810/run-report/139044914/

Пространственная сложность
    Без учета стека вызовов: O(1), так как не используется дополнительная память для хранения вершин или других структур.
    Со стеком вызовов: O(h), так как это максимальное количество одновременных вызовов при спуске по дереву.

Вычислительная сложность:
    Вычислительная сложность будет O(h) так как в худшем случае требуется пройти всю высоту дерева,
    если удаляемый ключ находится в самом низу или отсутствует.

Алгоритм считаю корректным так как после удаления любой вершины во всем дереве сохраняются свойства BST:
    - все значения в левом поддереве любой вершины меньше значения самой вершины.
    - все значения в правом поддереве больше.

В этом алгоритме удаление условно делится на четыре сценария.
1. Удаление вершины которая не имеет потомков.
    Вершина удаляется напрямую. Структура дерева не изменяется, свойства BST сохраняются.

2. Удаление вершины которая имеет только левого потомка.
    Вместо удаляемой вершины ее родитель начинает указывать напрямую на левое поддерево.
    Свойства BST сохраняются потому что:
        - родитель больше удаляемой вершины.
        - все вершины в левом поддереве меньше удаляемой вершины.
        - поддерево слева остается на правильной позиции по отношению к родителю.

3. Удаление вершины которая имеет только правого потомка.
    Все то же самое что и в предыдущем пункте, только наоборот.

3. Удаление вершины которая имеет и левого и правого потомков
    В этом случае требуется замена удаляемой вершины на минимальный элемент правого поддерева
    (самая левая вершина в правом поддереве).
    После замены свойства BST сохраняются потому что:
        - Новая вершина больше всех в левом поддереве и меньше всех в правом.
        - Поддерево переносимой вершины корректно перестраивается.
        - Если у переносимой вершины было правое поддерево, то оно поднимается на место этого узла сохраняя свойства BST
          так как это поддерево содержит только элементы которые больше переносимой вершины и меньше ее родителя.
        - Левого поддерева у переносимой вершины быть не может, так как эта вершина самая левая во всем поддереве.

*/
#ifndef REMOTE_JUDGE
struct Node {
    int   value;
    Node* left  = nullptr;
    Node* right = nullptr;

    Node(Node* left, Node* right, int value) : value(value), left(left), right(right) {
    }
};
#endif
#ifdef REMOTE_JUDGE
#include "solution.h"
#endif
#include <cassert>

Node* findLeftmost(Node* root) {
    if (root->left && root->left->left) {
        return findLeftmost(root->left);
    }

    if (root->left) {
        Node* left = root->left;
        root->left = left ? left->right : nullptr;

        return left;
    }

    return root;
}

Node* remove(Node* root, int key) {
    if (!root) {
        return nullptr;
    }

    if (root->value == key) {
        // Если вершина является листом, то ничего перестраивать не нужно
        if (!root->left && !root->right) {
            return nullptr;
        }

        // Если вершина имеет обоих потомков, то находим самый левый в правом дереве
        if (root->left && root->right) {
            Node* leftmost = findLeftmost(root->right);
            leftmost->left = root->left;
            leftmost->right = leftmost != root->right ? root->right : nullptr;

            return leftmost;
        }

        // Если вершина имеет только правого потомка, то на место этой вершины ставим этого правого потомка
        if (!root->left && root->right) {
            return root->right;
        }

        // Если вершина имеет только левого потомка, то на место этой вершины ставим этого левого потомка
        if (root->left && !root->right) {
            return root->left;
        }
    }

    if (root->value < key) {
        root->right = remove(root->right, key);
    }

    if (root->value > key) {
        root->left = remove(root->left, key);
    }

    return root;
}

#ifndef REMOTE_JUDGE
void test() {
    Node  node1({nullptr, nullptr, 2});
    Node  node2({&node1, nullptr, 3});
    Node  node3({nullptr, &node2, 1});
    Node  node4({nullptr, nullptr, 6});
    Node  node5({&node4, nullptr, 8});
    Node  node6({&node5, nullptr, 10});
    Node  node7({&node3, &node6, 5});
    Node* newHead = remove(&node7, 10);
    assert(newHead->value == 5);
    assert(newHead->right == &node5);
    assert(newHead->right->value == 8);
}

int main() {
    test();
}
#endif
