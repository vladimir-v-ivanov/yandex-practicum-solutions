#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack<int> order;

void bfs(vector<vector<int>>& adjacency, vector<bool>& statuses, const int v) {
    statuses[v] = true;

    for (const int u : adjacency[v]) {
        if (!statuses[u]) {
            bfs(adjacency, statuses, u);
        }
    }

    order.push(v);
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
    }

    for (int i = 0; i < V; i++) {
        if (!statuses[i]) {
            bfs(adjacency, statuses, i);
        }
    }

    while (!order.empty()) {
        cout << order.top() + 1 << " ";
        order.pop();
    }

    cout << endl;
}
