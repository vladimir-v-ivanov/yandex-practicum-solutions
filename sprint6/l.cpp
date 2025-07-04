#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

vector<unordered_set<int>> adjacency;
vector<int> sizes;

int main() {
    int V, E;
    cin >> V >> E;
    adjacency.resize(V, unordered_set<int>());
    sizes.resize(V, 0);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        if (u == v) {
            continue;
        }

        if (!adjacency[u].contains(v)) {
            adjacency[u].insert(v);
            sizes[u]++;
        }

        if (!adjacency[v].contains(u)) {
            adjacency[v].insert(u);
            sizes[v]++;
        }
    }

    for (const int size : sizes) {
        if (size != V - 1) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
}
