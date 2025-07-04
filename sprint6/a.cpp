#include <iostream>
#include <vector>

using namespace std;

int main() {
    int V, E;
    cin >> V >> E;
    vector adjacency(V, vector<int>());

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adjacency[u - 1].push_back(v);
    }

    for (int i = 0; i < V; i++) {
        cout << adjacency[i].size() << " ";

        for (const int vertex : adjacency[i]) {
            cout << vertex << " ";
        }

        cout << "\n";
    }

    cout << endl;
}
