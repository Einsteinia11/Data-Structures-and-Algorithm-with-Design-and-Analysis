/*
547. Number of Provinces
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.*/
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution
{
private:
    void dfs(int node, vector<int> adj_list[], int vis[])
    {
        vis[node] = 1;
        for (auto it : adj_list[node])
        {
            if (!vis[it])
            {
                dfs(it, adj_list, vis);
            }
        }
    }

public:
    int numProvinces(vector<vector<int>> &adj, int V)
    {
        // int vis[V] = {0};
        int vis[V];
        memset(vis, 0, sizeof(vis));
        vector<int> adj_list[V];

        // Construct the adjacency list from the adjacency matrix
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adj[i][j] == 1 && i != j)
                {
                    adj_list[i].push_back(j);
                    adj_list[j].push_back(i);
                }
            }
        }

        int count = 0; // Count the number of provinces

        // Perform DFS to find connected components (provinces)
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                count++;
                dfs(i, adj_list, vis);
            }
        }

        return count;
    }
};

int main()
{
    Solution solution;

    // Example usage
    int V = 3; // Number of cities (vertices)
    vector<vector<int>> adjacencyMatrix = {{1, 1, 0},
                                           {1, 1, 0},
                                           {0, 0, 1}};

    int provinces = solution.numProvinces(adjacencyMatrix, V);
    cout << "Number of provinces: " << provinces << endl;

    return 0;
}
/*
Example 1:

Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:

Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3

Constraints:

1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]*/