/*

Отчет: https://contest.yandex.ru/contest/26133/run-report/140801177/

Принцип работы:
    В решении используется префиксное дерево чтобы быстро проверять, начинается ли подстрока str с какого-либо из слов.
    Сначала идет построение дерева из всех слов словаря.
    Затем запускаем обход строки str используя динамическое программирование.
    Значение в массиве dp[i] = true означает, что префикс длины i можно собрать из слов словаря.
    На каждом индексе i проверяем если dp[i] = true, то идём по дереву начиная со str[i], и на каждом шаге проверяем, есть ли слово, заканчивающееся в этой точке.
    Если да то отмечаем dp[j] = true, где j — позиция после конца найденного слова.

Вычислительная сложность:
    Построение дерева занимает O(N * L), где L — средняя длина слова.
    Основной цикл по позиции str - O(N), и на каждой позиции может быть обход до глубины L по дереву.
    Общая сложность - O(N * L).

Пространственная сложность:
    Префиксное дерево занимает O(N * L) памяти.
    Массив dp — O(D).
    Общая пространственная сложность — O(N + D * L).
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
    bool finish = false;
    unordered_map<char, Node*> children;
};

void add(Node* root, const string& word) {
    Node* node = root;

    for (char c : word) {
        if (!node->children.contains(c)) {
            node->children[c] = new Node();
        }

        node = node->children[c];
    }

    node->finish = true;
}

int main() {
    string str;
    cin >> str;

    int num;
    cin >> num;

    const auto root = new Node();

    for (int i = 0; i < num; ++i) {
        string word;
        cin >> word;
        add(root, word);
    }

    const size_t len = str.size();
    vector dp(len + 1, false);
    dp[0] = true;

    for (int i = 0; i < len; ++i) {
        if (!dp[i]) {
            continue;
        }

        Node* node = root;

        for (int j = i; j < len; ++j) {
            char c = str[j];

            if (!node->children.contains(c)) {
                break;
            }

            node = node->children[c];

            if (node->finish) {
                dp[j + 1] = true;
            }
        }
    }

    cout << (dp[len] ? "YES" : "NO") << "\n";
}
