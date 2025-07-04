#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int current_color;
vector<vector<int>> colors;

void bfs(vector<vector<int>>& adjacency, vector<bool>& statuses, const int v) {
    statuses[v] = true;

    for (const int u : adjacency[v]) {
        if (!statuses[u]) {
            bfs(adjacency, statuses, u);
        }
    }

    if (current_color >= colors.size()) {
        colors.resize(current_color + 1);
    }

    colors[current_color].push_back(v);
}

int main() {
    int V, E;
    cin >> V >> E;

    vector statuses(V, false);
    vector<vector<int>> adjacency(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adjacency[u].push_back(v);
        adjacency[v].push_back(u);
    }

    current_color = 1;
    for (int i = 0; i < V; i++) {
        if (!statuses[i]) {
            bfs(adjacency, statuses, i);
            current_color++;
        }
    }

    cout << current_color - 1;

    for (auto& v : colors) {
        ranges::sort(v);

        for (const int u : v) {
            cout << u + 1 << " ";
        }

        cout << "\n";
    }

    cout << endl;
}
