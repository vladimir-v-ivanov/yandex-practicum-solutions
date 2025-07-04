#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void bfs(vector<bool>& statuses, vector<vector<int>>& adjacency, const int vertex) {
    statuses[vertex] = true;
    cout << vertex + 1 << " ";

    for (const int v : adjacency[vertex]) {
        if (!statuses[v]) {
            bfs(statuses, adjacency, v);
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    vector statuses(V, false);
    vector<vector<int>> adjacency(V);

    for (int k = 0; k < E; k++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        adjacency[u].push_back(v);
        adjacency[v].push_back(u);
    }

    for (auto& neighbors : adjacency) {
        ranges::sort(neighbors);
    }

    int start;
    cin >> start;

    bfs(statuses, adjacency, start - 1);
}
