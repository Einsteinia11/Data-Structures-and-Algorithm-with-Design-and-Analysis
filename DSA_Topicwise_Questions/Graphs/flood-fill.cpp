/*
733. Flood Fill
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.*/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int newColor,
             int delrow[], int delcol[], int iniColor)
    {
        ans[row][col] = newColor; // color to be filled
        int n = image.size();     // row size
        int m = image[0].size();  // column size
        // There are exactly 4 neighbors
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            // Check for valid coordinates
            // Then check for the same initial color and unvisited pixel
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor)
            {
                dfs(nrow, ncol, ans, image, newColor, delrow, delcol, iniColor);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int initial = image[sr][sc];
        vector<vector<int>> ans = image;
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};
        dfs(sr, sc, ans, image, newColor, delrow, delcol, initial);
        return ans;
    }
};

int main()
{
    // Example usage:
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}};
    int sr = 1;
    int sc = 1;
    int newColor = 2;

    Solution solution;
    vector<vector<int>> filledImage = solution.floodFill(image, sr, sc, newColor);

    cout << "Flood Fill Result:" << endl;
    for (const vector<int> &row : filledImage)
    {
        for (int pixel : row)
        {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}
/*
Example 1:

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.

Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
Output: [[0,0,0],[0,0,0]]
Explanation: The starting pixel is already colored 0, so no changes are made to the image.


Constraints:

m == image.length
n == image[i].length
1 <= m, n <= 50
0 <= image[i][j], color < 216
0 <= sr < m
0 <= sc < n*/
