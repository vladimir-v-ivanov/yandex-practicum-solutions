#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class NodeType { Leaf, Repeat, Concat };
struct Node {
    const NodeType type;
    size_t total_len; // длина распакованного фрагмента
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
// asdsd2[jwcn]sasa2[1[emgu]aa3[foo]]1[bzgy]
// asdsdjwcnjwcnasasemguemgugzgy
Concat* create_nodes(const string& str, const int start, const int end) {
    auto* concat = new Concat(0);

    int leaf_start = start;
    for (int i = start; i < end; ++i) {
        // Переходим к следующей цифре
        size_t digit_spos = 0;
        while (!isdigit(str[i]) && i < end) {
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
        while (str[i] != '[' && i < end) {
            ++i;
        }

        if (str[i] == '[') {
            // Ищем закрывающую скобку
            const int times     = atoi(str.substr(digit_spos, i - digit_spos).c_str());
            const int new_start = i + 1;
            int depth           = 1;

            while (depth > 0 && i < end) {
                i++;
                if (str[i] == '[') {
                    ++depth;
                } else if (str[i] == ']') {
                    --depth;
                }
            }
            const int new_end = i;

            // Оптимизация: разворачиваем Concat с одним потомком
            Repeat* repeat;
            if (auto* node = create_nodes(str, new_start, new_end); node->children.size() == 1) {
                auto* child_node = node->children[0];
                node->children.clear();
                repeat = new Repeat(times, child_node);
                concat->children.push_back(new Repeat(times, child_node));

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

void clean(const Node* node) {
    if (node == nullptr) {
        return;
    }

    if (node->type == NodeType::Concat) {
        for (const Node* child : static_cast<const Concat*>(node)->children) {
            clean(child);
        }
    }

    if (node->type == NodeType::Repeat) {
        clean(static_cast<const Repeat*>(node)->child);
    }

    delete node;
}

int main() {
    // int num;
    // cin >> num;
    //
    // vector<string> strings(num);
    // string str;
    //
    // for (int i = 0; i < num; i++) {
    //     cin >> str;
    //     strings[i] = str;

    string str       = "asdsd2[jwcn]sasa2[1[emgu]aa3[foo]]1[bzgy]";
    const auto* root = create_nodes(str, 0, str.size());
    clean(root);
    // }
    //
    // vector dp(num, 0);
}
