/*
53. Maximum Subarray
Given an integer array nums, find the subarray with the largest sum, and return its sum.
Examples are below the code and the constraints
 */
#include <iostream>
#include <vector>
#include <climits>

// Function to find the maximum subarray sum
int maxSubArray(std::vector<int> &nums)
{
    int maxi = INT_MIN; // Initialize the maximum sum to negative infinity
    int ans = 0;        // Initialize the current subarray sum to zero
    for (int i = 0; i < nums.size(); i++)
    {
        ans = ans + nums[i]; // Add the current element to the current subarray sum

        maxi = std::max(maxi, ans); // Update the maximum sum if the current subarray sum is larger
        if (ans < 0)
        {
            ans = 0; // Reset the current subarray sum to zero if it becomes negative
        }
    }
    return maxi; // Return the maximum subarray sum
}

int main()
{
    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // Example input array
    int maxSum = maxSubArray(nums);                          // Call the function to find the maximum subarray sum

    std::cout << "Maximum subarray sum: " << maxSum << std::endl; // Print the result

    return 0;
}
/*
Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.


Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
*/
