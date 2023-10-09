/*
128. Longest Consecutive Sequence
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.Examples and constraints are below the code
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    int longestConsecutive(std::vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0; // If the input vector is empty, return 0 as there are no consecutive elements.

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int longest = 1;
        int curr_cnt = 0; // Initialize the current consecutive sequence length to 0.
        int last_smaller = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] - 1 == last_smaller)
            {
                // If the current number is consecutive to the previous number, increment the current consecutive sequence length.
                curr_cnt += 1;
                last_smaller = nums[i];
            }
            else if (nums[i] != last_smaller)
            {
                // If the current number is not equal to the last smaller number, start a new consecutive sequence.
                curr_cnt = 1;
                last_smaller = nums[i];
            }

            longest = max(longest, curr_cnt); // Update the longest consecutive sequence length.
        }

        return longest;
    }
};

int main()
{
    // Example usage:
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    Solution solution;
    int longestConsecutive = solution.longestConsecutive(nums);
    std::cout << "Longest Consecutive Sequence Length: " << longestConsecutive << std::endl;
    return 0;
}

/*
Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Constraints:

0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9*/