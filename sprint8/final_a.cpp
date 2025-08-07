/*
Отчет: https://contest.yandex.ru/contest/26133/run-report/140799950/

Принцип работы:
        В решении строится AST-дерево, которое хранит структуру запакованной строки без полного разворачивания.
        Каждая нода содержит либо прямой фрагмент исходного текста, либо информацию о повторении или конкатенации.
        Это позволяет получать любой символ “на лету” по его индексу так, как если бы строка была распакована,
        но без затрат памяти на всю развёрнутую строку и без копирования каждого символа в памяти при развертывании.

        Для поиска общего префикса мы проходим по позициям от 0 до длины наименьшей строки.
        На каждой позиции i сначала получаем опорный символ из первой строки.
        Затем перебираем все остальные строки и сравниваем символ на той же позиции с опорным.
        Как только на какой-либо строке он отличается, мы прерываем оба цикла и выводим накопленный префикс.

Вычислительная сложность:
    Вначале идет построение АСТ дерева, которое занимает O(M), где M это общая длина всех сжатых строк.
    Далее все строки обрабатываются во внешнем цикле длины N, по количеству строк.
    Во внутреннем цикле каждая строка перебирается посимвольно, что занимает O(L), где L это длина самой короткой строки,
    так как нет смысла продолжать обход, когда достигнут конец одной из строк.
    На каждой итерации вложенного цикла происходит поиск символа в АСТ дереве по индексу, что занимает O(H), по глубине дерева.
    Общая вычислительная сложность в худшем случае O(N M L H)

Пространственная сложность:
    Пространственная сложность O(M H), где M это длина всех сжатых строк, и H это стек вызовов по максимальной глубине дерева АСТ.
    Без учета стека пространственная сложность O(M).
*/

#include <climits>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class NodeType { Leaf, Repeat, Concat };
struct Node {
    const NodeType type;
    size_t total_len;
    virtual ~Node() = default;
    Node(const NodeType t, const size_t s) : type(t), total_len(s) {}
};
struct Leaf final : Node {
    const size_t start;
    const size_t end;
    const size_t length;
    Leaf(const size_t s, const size_t e, const size_t l) : Node{NodeType::Leaf, e - s}, start(s), end(e), length(l) {}
};
struct Concat final : Node {
    vector<Node*> children;
    explicit Concat(const size_t l) : Node{NodeType::Concat, 0} {
        this->total_len = l;
    }
};
struct Repeat final : Node {
    const int times;
    Node* child;
    Repeat(const int t, Node* c) : Node{NodeType::Repeat, 0}, times(t), child(c) {
        this->total_len = c->total_len * times;
    }
};
// asdsd2[jwcn]sasa2[1[emgu]aa3[foo]]1[bzgy]fas
// asdsdjwcnjwcnsasemguaafoofoofooemguaafoofoofooemguaafoofoofoobzgyfas
Concat* create_nodes(const string& str, const size_t start, const size_t end) {
    auto* concat = new Concat(0);

    size_t leaf_start = start;
    for (size_t i = start; i < end; ++i) {
        // Переходим к следующей цифре
        size_t digit_spos = 0;
        while (i < end && !isdigit(str[i])) {
            ++i;
        }

        if (isdigit(str[i])) {
            digit_spos = i;
        }

        // Завершаем текущую строку и добавляем в Concat
        if (leaf_start < i) {
            auto* leaf = new Leaf(leaf_start, i, i - leaf_start);
            concat->children.push_back(leaf);
            concat->total_len += leaf->total_len;
        }

        // Ищем открывающую скобку
        while (i < end && str[i] != '[') {
            ++i;
        }

        if (str[i] == '[') {
            // Ищем закрывающую скобку
            const int times        = atoi(str.substr(digit_spos, i - digit_spos).c_str());
            const size_t new_start = i + 1;
            int depth              = 1;

            while (i < end && depth > 0) {
                i++;
                if (str[i] == '[') {
                    ++depth;
                } else if (str[i] == ']') {
                    --depth;
                }
            }
            const size_t new_end = i;

            // Оптимизация: разворачиваем Concat с одним потомком
            Repeat* repeat;
            if (auto* node = create_nodes(str, new_start, new_end); node->children.size() == 1) {
                auto* child_node = node->children[0];
                node->children.clear();
                repeat = new Repeat(times, child_node);
                delete node;
            } else {
                repeat = new Repeat(times, node);
            }

            concat->children.push_back(repeat);
            concat->total_len += repeat->total_len;
            leaf_start = i + 1;
        }
    }

    return concat;
}

void cleanup(Node* node) {
    if (node == nullptr) {
        return;
    }

    if (node->type == NodeType::Concat) {
        for (Node* child : static_cast<Concat*>(node)->children) {
            cleanup(child);
        }
    }

    if (node->type == NodeType::Repeat) {
        cleanup(static_cast<Repeat*>(node)->child);
    }

    delete node;
}

char char_at(const Node* node, const string& str, const size_t pos) {
    if (node->type == NodeType::Leaf) {
        const auto leaf = static_cast<const Leaf*>(node);

        return str[leaf->start + pos];
    }

    if (node->type == NodeType::Concat) {
        const auto concat = static_cast<const Concat*>(node);
        size_t offset     = pos;

        for (const auto* child : concat->children) {
            if (offset < child->total_len) {
                return char_at(child, str, offset);
            }

            offset -= child->total_len;
        }
    }

    if (node->type == NodeType::Repeat) {
        const auto repeat = static_cast<const Repeat*>(node);

        return char_at(repeat->child, str, pos % repeat->child->total_len);
    }

    return '\0';
}

int main() {
    int num;
    cin >> num;

    vector<Concat*> roots(num);
    vector<string> strings(num);
    string prefix;

    for (int i = 0; i < num; i++) {
        cin >> strings[i];
        roots[i] = create_nodes(strings[i], 0, strings[i].size());
    }

    size_t min_len = LLONG_MAX;

    for (const auto root : roots) {
        min_len = min(min_len, root->total_len);
    }

    for (size_t i = 0; i < min_len; ++i) {
        const char c = char_at(roots[0], strings[0], i);

        bool equal = true;
        for (int j = 1; j < num; ++j) {
            if (char_at(roots[j], strings[j], i) != c) {
                equal = false;
                break;
            }
        }

        if (!equal)
            break;

        prefix.push_back(c);
    }

    cout << prefix << endl;

    for (int i = 0; i < num; i++) {
        cleanup(roots[i]);
    }

    roots.clear();
}
