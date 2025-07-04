#include <iostream>
#include <vector>

using namespace std;

int main() {
    int V, E;
    cin >> V >> E;
    vector adjacency(V, vector(V, 0));

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adjacency[u - 1][v - 1] = 1;
    }

    for (int i = 0; i < V; i++) {
        for (const int adj : adjacency[i]) {
            cout << adj << " ";
        }

        cout << "\n";
    }

    cout << endl;
}
