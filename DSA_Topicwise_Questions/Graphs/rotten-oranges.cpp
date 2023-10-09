/*
994. Rotting Oranges
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        int vis[n][m];

        // Initialize the vis array and queue with rotten oranges
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                else
                {
                    vis[i][j] = 0;
                }
            }
        }

        int tm = 0; // Initialize the time

        // Define directions for moving in up, down, left, and right directions
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm, t);

            q.pop();

            // Explore neighboring cells
            for (int i = 0; i < 4; i++)
            {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                // Check if the neighboring cell is within bounds, not rotten, and not visited
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1)
                {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                }
            }
        }

        // Check if there are any fresh oranges left
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] != 2 && grid[i][j] == 1)
                {
                    return -1; // If there are fresh oranges left, return -1
                }
            }
        }

        return tm; // Return the time taken for all oranges to rot
    }
};

int main()
{
    // Example usage:
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}};

    Solution solution;
    int timeToRot = solution.orangesRotting(grid);

    cout << "Time to rot all oranges: " << timeToRot << endl;

    return 0;
}
/*
Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.*/
