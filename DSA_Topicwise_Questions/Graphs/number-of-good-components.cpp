/*
Given an undirected graph with V vertices(numbered from 1 to V) and E edges. Find the number of good components in the graph.
A component of the graph is good if and only if the component is a fully connected component.
Note: A fully connected component is a subgraph of a given graph such that there's an edge between every pair of vertices in a component, the given graph can be a disconnected graph. Consider the adjacency list from vertices 1.*/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // DFS function to traverse the graph
    void dfs(int v, int &vertices, int &edges, vector<vector<int>> &adj,
             vector<int> &visited)
    {
        visited[v] = 1;
        vertices++;             // Counting the number of vertices
        edges += adj[v].size(); // Counting the number of edges
        for (auto to : adj[v])
        {
            if (!visited[to])
            {
                dfs(to, vertices, edges, adj, visited);
            }
        }
    }

    // Function to find the number of "good" components
    int findNumberOfGoodComponent(int V, vector<vector<int>> &adj)
    {
        int ans = 0;
        vector<int> visited(V + 1, 0);

        for (int i = 1; i <= V; i++)
        {
            // Check if the vertex is visited or not
            if (!visited[i])
            {
                int vertices = 0, edges = 0;
                dfs(i, vertices, edges, adj, visited);
                // Checking if the component is "good"
                edges /= 2;
                if (edges == (vertices * (vertices - 1)) / 2)
                    ans++;
            }
        }
        return ans;
    }
};

int main()
{
    // Example usage:
    int V = 5; // Number of vertices
    vector<vector<int>> adj(V + 1);

    // Initialize the adjacency list for your graph here
    // ...

    Solution solution;
    int numberOfGoodComponents = solution.findNumberOfGoodComponent(V, adj);

    cout << "Number of good components: " << numberOfGoodComponents << endl;

    return 0;
}
/*
Example 1:

Input:


E=3 V=3
adj:
{{1, 2},
 {1, 3},
 {3, 2}}
Output: 1
Explanation: We can see that there is only one
component in the graph and in this component
there is a edge between any two vertces.
Example 2:

Input:

E=5 V=7
adj:
{{1, 2},
 {7, 2},
 {3, 5},
 {3, 4},
 {4, 5}}
Output: 2
Explanation: We can see that there are 3 components
in the graph. For 1-2-7 there is no edge between
1 to 7, so it is not a fully connected component.
Rest 2 are individually fully connected component.

Expected Time Complexity: O(V+E)
Expected Auxiliary Space: O(depth of the graph)

Constraints:
1 ≤ V, E ≤ 104*/