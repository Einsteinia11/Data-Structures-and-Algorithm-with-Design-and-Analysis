/*
561. Array Partition
Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // Function to find the maximum sum of pairs after sorting the array
    int arrayPairSum(vector<int> &nums)
    {
        // Sort the input vector in ascending order
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int ans = 0;

        // Iterate over the sorted array in steps of 2 and accumulate the minimum of each pair
        for (int i = n - 1; i >= 0; i -= 2)
        {
            ans += min(nums[i], nums[i - 1]);
        }

        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 4, 3, 2};

    int result = solution.arrayPairSum(nums);

    cout << "Maximum sum of pairs: " << result << endl;

    return 0;
}
/*
Example 1:

Input: nums = [1,4,3,2]
Output: 4
Explanation: All possible pairings (ignoring the ordering of elements) are:
1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
So the maximum possible sum is 4.
Example 2:

Input: nums = [6,2,6,5,1,2]
Output: 9
Explanation: The optimal pairing is (2, 1), (2, 5), (6, 6). min(2, 1) + min(2, 5) + min(6, 6) = 1 + 2 + 6 = 9.


Constraints:

1 <= n <= 104
nums.length == 2 * n
-104 <= nums[i] <= 104*/