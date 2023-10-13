/*
200. Number of Islands
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water. Examples are below the code:-*/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    // Depth-First Search (DFS) function to explore the island
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        // Check if the current cell is within bounds, is part of the island, and not visited
        if (row >= 0 && row < n && col >= 0 && col < m && grid[row][col] == '1' && !vis[row][col])
        {
            // Mark the current cell as visited
            vis[row][col] = 1;

            // Recursively explore adjacent cells (up, down, left, right)
            dfs(row + 1, col, vis, grid);
            dfs(row - 1, col, vis, grid);
            dfs(row, col + 1, vis, grid);
            dfs(row, col - 1, vis, grid);
        }
    }

public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0)); // Visited array to keep track of visited cells
        int counter = 0;                               // Initialize the counter for the number of islands

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (!vis[row][col] && grid[row][col] == '1')
                {
                    // If the cell is not visited and is part of an island, start exploring it
                    dfs(row, col, vis, grid);
                    counter++; // Increment the counter for each new island found
                }
            }
        }

        return counter; // Return the total number of islands
    }
};

int main()
{
    // Example grid representing islands (1s) and water (0s)
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};

    Solution solution;
    int numIslands = solution.numIslands(grid);

    cout << "Number of islands: " << numIslands << endl;

    return 0;
}
/*
Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.*/
