#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

enum class Color {
    White,
    Gray,
    Black,
};

vector<vector<int>> adjacency;
vector<Color>       colors;
vector<int>         distances;

int max_distance = 0;

void bfs(int v) {
    queue<int> q;
    q.push(v);
    colors[v]    = Color::Gray;
    distances[v] = 0;

    while (!q.empty()) {
        v = q.front();
        q.pop();

        for (const auto u : adjacency[v]) {
            if (colors[u] == Color::White) {
                distances[u] = distances[v] + 1;
                colors[u]    = Color::Gray;
                q.push(u);
            }
        }

        if (colors[v] != Color::Black) {
            colors[v]    = Color::Black;
            max_distance = max(max_distance, distances[v]);
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    adjacency.resize(V);
    colors.resize(V, Color::White);
    distances.resize(V, 0);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        adjacency[u].push_back(v);
        adjacency[v].push_back(u);
    }

    for (int i = 0; i < V; i++) {
        ranges::sort(adjacency[i]);
    }

    int start;
    cin >> start;

    bfs(start - 1);

    cout << max_distance << endl;
}
