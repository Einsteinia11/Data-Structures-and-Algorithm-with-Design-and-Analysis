/*3. Longest Substring Without Repeating Characters*/
/*
Given a string s, find the length of the longest substring without repeating characters.*/
#include <iostream>
#include <string>
#include <unordered_set>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        int left = 0;  // Initialize the left pointer of the sliding window
        int right = 0; // Initialize the right pointer of the sliding window
        std::unordered_set<char> stt;
        int len = 0;

        while (right != s.size())
        {
            char temp = s[right]; // Get the character at the right pointer
            char temp2 = s[left]; // Get the character at the left pointer

            if (stt.find(temp) == stt.end())
            {
                stt.insert(temp); // Add the character at the right pointer to the set
                right++;          // Move the right pointer to the right
            }
            else
            {
                stt.erase(temp2); // Remove the character at the left pointer from the set
                left++;           // Move the left pointer to the right
            }

            len = std::max(len, right - left); // Update the maximum length

            // Print the current maximum length (optional, for debugging)
            std::cout << "Current maximum length: " << len << std::endl;
        }

        return len; // Return the length of the longest substring without repeating characters
    }
};

int main()
{
    Solution solution;              // Create an instance of the Solution class
    std::string input = "abcabcbb"; // Example input string

    int result = solution.lengthOfLongestSubstring(input); // Call the function to find the longest substring

    std::cout << "Length of the longest substring: " << result << std::endl; // Print the result

    return 0;
}

/*

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.*/