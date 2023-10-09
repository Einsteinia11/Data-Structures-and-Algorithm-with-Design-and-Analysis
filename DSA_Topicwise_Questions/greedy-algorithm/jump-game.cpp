/*
55. Jump Game
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.*/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // Function to determine if you can reach the last index using jumps
    bool canJump(vector<int> &nums)
    {
        int len = nums.size();
        int reach = 0; // Initialize the maximum reachable index

        for (int i = 0; i < len; i++)
        {
            if (i > reach)
            {
                return false; // If you can't reach the current index, return false
            }

            // Update the maximum reachable index using the current element
            reach = max(reach, i + nums[i]);
        }

        return true; // If you can reach the end, return true
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {2, 3, 1, 1, 4}; // Example input, change this to your desired input

    bool result = solution.canJump(nums);

    cout << "Can you reach the last index? " << (result ? "Yes" : "No") << endl;

    return 0;
}

/*
Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.


Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105
*/