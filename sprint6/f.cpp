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
vector<int>         distances;

void bfs(const int start) {
    queue<int> planned;
    planned.push(start);
    color[start] = Color::Gray;
    distances[start] = 0;

    while (!planned.empty()) {
        const int u = planned.front();
        planned.pop();

        for (int v : adjacency[u]) {
            if (color[v] == Color::White) {
                color[v] = Color::Gray;
                distances[v] = distances[u] + 1;
                planned.push(v);
            }
        }

        if (color[u] != Color::Black) {
            color[u] = Color::Black;
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    adjacency.reserve(V);
    color.reserve(V);
    distances.resize(V, -1);

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

    int start, end;
    cin >> start >> end;

    bfs(start - 1);

    cout << (distances.size() > end - 1 ? distances[end - 1] : -1) << endl;
}
