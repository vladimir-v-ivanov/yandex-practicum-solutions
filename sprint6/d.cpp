#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

enum class Color {
    White,
    Gray,
    Black
};

vector<vector<int>> adjacency;
vector<Color>       color;

void bfs(const int start) {
    queue<int> planned;
    planned.push(start);
    color[start] = Color::Gray;

    while (!planned.empty()) {
        const int u = planned.front();
        planned.pop();

        for (int v : adjacency[u]) {
            if (color[v] == Color::White) {
                color[v] = Color::Gray;
                planned.push(v);
            }
        }

        if (color[u] != Color::Black) {
            cout << u + 1 << " ";
            color[u] = Color::Black;
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    adjacency.reserve(V);
    color.reserve(V);

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
}
