#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
public:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        stack<int> stk;
        stk.push(start);

        while (!stk.empty()) {
            int current = stk.top();
            stk.pop();

            if (!visited[current]) {
                cout << current << " ";
                visited[current] = true;
            }

            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    stk.push(neighbor);
                }
            }
        }
    }
};

int main() {
    int V, E; // Number of vertices and edges
    cin >> V >> E;
    Graph g(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int start; // Starting vertex for DFS
    cin >> start;

    cout << "DFS starting from vertex " << start << ":\n";
    g.DFS(start);

    return 0;
}
