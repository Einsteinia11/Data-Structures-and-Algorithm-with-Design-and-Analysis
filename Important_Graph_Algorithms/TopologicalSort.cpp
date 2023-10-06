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

    void topologicalSortUtil(int v, vector<bool>& visited, stack<int>& st) {
        visited[v] = true;

        for (int i : adj[v]) {
            if (!visited[i]) {
                topologicalSortUtil(i, visited, st);
            }
        }

        st.push(v);
    }

    void topologicalSort() {
        vector<bool> visited(V, false);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                topologicalSortUtil(i, visited, st);
            }
        }

        cout << "Topological Sorting Order:\n";
        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
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

    cout << "Topological Sort:\n";
    g.topologicalSort();

    return 0;
}
