#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    string& value;
    string tmp_value;
    int times = 0;
    int start = 0;
    int end   = 0;
    vector<Node*> children;
};

char getch(const string& line, const int pos) {
    return line[pos];
}
// asdsd2[jwcn]sasa2[1[emgu]]1[bzgy]
vector<Node*> create_nodes(string& str, int start, int end) {
    vector<Node*> nodes;
    bool found = false;

    int i = start;
    while (i < end) {
        if (str[i] >= '0' && str[i] <= '9') {
            found          = true;
            auto* node     = new Node(str, str.substr(start, i - start - 1), 1, start, i);
            const int open = static_cast<int>(str.find('[', i));
            int close      = static_cast<int>(str.find(']', open));

            node->children = create_nodes(str, open + 1, close + 1);

            while (str[close] == ']') {
                close++;
            }

            i     = close;
            start = close;

            nodes.push_back(node);
            continue;
        }

        i++;
    }

    if (!found) {
        nodes.push_back(new Node(str, str.substr(start, end - start - 1), 1, start, end));
    }

    return nodes;
}

int main() {
    int num;
    cin >> num;

    vector<string> strings(num);
    string str;

    for (int i = 0; i < num; i++) {
        cin >> str;
        strings[i] = str;

        const auto* root = new Node(str, str.substr(0, 0), 1, 0, 0, create_nodes(str, 0, str.length()));
        delete root;
    }
    vector dp(num, 0);
}
