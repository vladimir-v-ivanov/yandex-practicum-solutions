#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// AST node types:
//   0 = literal leaf, contains a string s
//   1 = repetition, repeat child times
//   2 = concatenation of a vector of children
struct Node {
    int type;
    string s; // for leaf
    ll times    = 1; // for repetition
    Node* child = nullptr; // for repetition
    vector<Node*> ch; // for concatenation

    Node(int t = 2) : type(t) {}
};

// parse a bracket‐encoding from str[pos…] until ']' or end
// returns the parsed node and advances pos past the ']'
Node* parse(const string& str, int& pos) {
    vector<Node*> parts;
    while (pos < (int) str.size() && str[pos] != ']') {
        if (isdigit(str[pos])) {
            // read the repeat count
            ll cnt = 0;
            while (pos < (int) str.size() && isdigit(str[pos])) {
                cnt = cnt * 10 + (str[pos] - '0');
                pos++;
            }
            // skip the '['
            pos++;
            // parse the inside
            Node* sub = parse(str, pos);
            // skip the ']'
            pos++;
            // make a repetition node
            Node* rep  = new Node(1);
            rep->times = cnt;
            rep->child = sub;
            parts.push_back(rep);
        } else {
            // read a run of letters
            int st = pos;
            while (pos < (int) str.size() && isalpha(str[pos])) {
                pos++;
            }
            Node* leaf = new Node(0);
            leaf->s    = str.substr(st, pos - st);
            parts.push_back(leaf);
        }
    }
    // if only one part, return it
    if (parts.size() == 1) {
        return parts[0];
    }
    // otherwise concatenate them
    Node* cat = new Node(2);
    cat->ch   = move(parts);
    return cat;
}

// free all nodes in the subtree
void clean(Node* u) {
    if (!u) {
        return;
    }
    if (u->type == 1) {
        clean(u->child);
    } else if (u->type == 2) {
        for (auto* c : u->ch) {
            clean(c);
        }
    }
    delete u;
}

// an iterator over the expanded string of a node
struct Iterator {
    struct State {
        Node* node;
        ll done; // for repetition: how many repeats finished
        int idx; // for concat: index of next child
        int pos; // for leaf: position in s
    };
    vector<State> st;

    Iterator(Node* root) {
        st.push_back({root, 0, 0, 0});
    }
    // is there another character?
    bool hasNext() const {
        return !st.empty();
    }
    // consume and return next character
    char next() {
        while (!st.empty()) {
            State& top = st.back();
            Node* u    = top.node;
            if (u->type == 0) {
                // leaf
                if (top.pos < (int) u->s.size()) {
                    return u->s[top.pos++];
                }
                // leaf done
                st.pop_back();
            } else if (u->type == 2) {
                // concatenation
                if (top.idx < (int) u->ch.size()) {
                    Node* c = u->ch[top.idx++];
                    st.push_back({c, 0, 0, 0});
                } else {
                    st.pop_back();
                }
            } else {
                // repetition
                if (top.done < u->times) {
                    top.done++;
                    // iterate its child
                    st.push_back({u->child, 0, 0, 0});
                } else {
                    st.pop_back();
                }
            }
        }
        // no chars left
        return '\0';
    }
    // peek at the next character without consuming it
    char peek() const {
        Iterator tmp = *this;
        return tmp.next();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Node*> roots(n);
    for (int i = 0; i < n; i++) {
        string enc;
        cin >> enc;
        int pos  = 0;
        roots[i] = parse(enc, pos);
    }

    // create one iterator per string
    vector<Iterator> its;
    its.reserve(n);
    for (auto* r : roots) {
        its.emplace_back(r);
    }

    // build the longest common prefix one char at a time
    string lcp;
    while (its[0].hasNext()) {
        char c0    = its[0].peek();
        bool match = (c0 != '\0');
        // check all others
        for (int i = 1; i < n && match; i++) {
            if (!its[i].hasNext() || its[i].peek() != c0) {
                match = false;
            }
        }
        if (!match) {
            break;
        }
        // consume from all
        for (int i = 0; i < n; i++) {
            its[i].next();
        }
        lcp.push_back(c0);
    }

    // output the LCP
    cout << lcp << "\n";

    // cleanup
    for (auto* r : roots) {
        clean(r);
    }
    return 0;
}
