/*
847. Shortest Path Visiting All Nodes
You have an undirected, connected graph of n nodes labeled from 0 to n - 1. You are given an array graph where graph[i] is a list of all the nodes connected with node i by an edge.

Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int shortestPathLength(vector<vector<int>> &graph)
    {
        // If there is only one node in the graph, the shortest path is 0.
        if (graph.size() == 1)
            return 0;

        int n = graph.size();          // Number of nodes in the graph
        int finalState = (1 << n) - 1; // Final state where all nodes are visited
        queue<pair<int, int>> q;       // Queue to perform BFS

        // Create a 2D visited array to keep track of visited nodes with their state.
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));

        // Initialize the queue with all nodes and their initial state.
        for (int i = 0; i < n; i++)
        {
            q.push({i, 1 << i});
            // If a node itself is the final state, return 0 as the shortest path.
            if ((1 << i) == finalState)
                return 0;
            visited[i][1 << i] = true;
        }

        int count = 0; // Initialize the shortest path length.

        while (!q.empty())
        {
            int size = q.size(); // Number of nodes at the current level
            count++;             // Increment the shortest path length.

            // Process nodes at the current level.
            for (int i = 0; i < size; i++)
            {
                int next = q.front().first;     // Current node
                int bitMask = q.front().second; // Current state
                q.pop();

                // Iterate through neighbors of the current node.
                for (int it : graph[next])
                {
                    int newMask = bitMask | (1 << it); // Update the state by marking the neighbor as visited.

                    if (!visited[it][newMask])
                    {
                        // If the new state is the final state, return the shortest path length.
                        if (newMask == finalState)
                            return count;

                        visited[it][newMask] = true;
                        q.push({it, newMask});
                    }
                }
            }
        }

        // If no shortest path is found, return 0.
        return 0;
    }
};

int main()
{
    // Example usage:
    vector<vector<int>> graph = {{1, 2, 3}, {0}, {0}, {0}};
    Solution solution;
    int shortestPath = solution.shortestPathLength(graph);
    cout << "Shortest Path Length: " << shortestPath << endl;
    return 0;
}
/*
Example 1:


Input: graph = [[1,2,3],[0],[0],[0]]
Output: 4
Explanation: One possible path is [1,0,2,0,3]
Example 2:


Input: graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
Output: 4
Explanation: One possible path is [0,1,4,2,3]


Constraints:

n == graph.length
1 <= n <= 12
0 <= graph[i].length < n
graph[i] does not contain i.
If graph[a] contains b, then graph[b] contains a.
The input graph is always connected.*/
