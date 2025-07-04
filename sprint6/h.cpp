#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int counter;

void bfs(vector<vector<int>>& adjacency, vector<bool>& statuses, vector<int>& entries, vector<int>& leaves, const int v) {
    counter++;
    entries[v] = counter;
    statuses[v] = true;

    for (const int u : adjacency[v]) {
        if (!statuses[u]) {
            bfs(adjacency, statuses, entries, leaves, u);
        }
    }

    counter++;
    leaves[v] = counter;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector statuses(V, false);
    vector entries(V, 0);
    vector leaves(V, 0);
    vector<vector<int>> adjacency(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adjacency[u].push_back(v);
    }

    for (auto& neighbors : adjacency) {
        ranges::sort(neighbors);
    }

    counter = 0;
    bfs(adjacency, statuses, entries, leaves, 0);

    for (int i = 0; i < V; i++) {
        cout << entries[i] - 1 << " " << leaves[i] - 1 << "\n";
    }

    cout << endl;
}
