/*
347. Top K Frequent Elements
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue> // Include the necessary header for using priority_queue
using namespace std;

class Solution
{
public:
    // Function to find the top K frequent elements in an array
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>> pq; // Create a max heap (priority queue) to store elements based on frequency

        // Count the frequency of each element in the input vector and store it in the hash map
        for (auto i : nums)
        {
            mp[i]++;
        }

        nums.clear(); // Clear the original vector to prepare it for storing the top K frequent elements

        // Push elements from the hash map into the max heap with frequency as the key
        for (auto i : mp)
        {
            pq.push({i.second, i.first});
        }

        // Pop the top K elements from the max heap and store them in the 'nums' vector
        for (int i = 0; i < k; i++)
        {
            nums.push_back(pq.top().second);
            pq.pop();
        }

        return nums; // Return the 'nums' vector containing the top K frequent elements
    }
};

int main()
{
    // Create a vector of integers for testing
    std::vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    Solution solution;

    std::vector<int> topK = solution.topKFrequent(nums, k);

    std::cout << "Top " << k << " Frequent Elements: ";
    for (auto element : topK)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}

/*
Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]

Constraints:

1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
*/