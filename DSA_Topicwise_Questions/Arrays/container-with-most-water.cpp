/*
11. Container With Most Water
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container. Examples are below the code:-
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxArea(std::vector<int> &height)
    {
        int maxarea = 0;           // Initialize the maximum area to 0
        int l = 0;                 // Initialize the left pointer to the start
        int r = height.size() - 1; // Initialize the right pointer to the end size

        // Continue the loop until the left and right pointers meet
        while (l < r)
        {
            int h = min(height[l], height[r]);   // Calculate the minimum height between the two pointers
            maxarea = max(maxarea, h * (r - l)); // Calculate the current area and update the maximum area if necessary

            // Move the pointer that points to the shorter height towards the other pointer
            if (height[l] < height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return maxarea; // Return the maximum area
    }
};

int main()
{
    // Example usage:
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution solution;
    int maxArea = solution.maxArea(height);
    std::cout << "Maximum Area: " << maxArea << std::endl;
    return 0;
}

/*
Example 1:

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1
Constraints:

n == height.length
2 <= n <= 10^5
0 <= height[i] <= 10^4
*/