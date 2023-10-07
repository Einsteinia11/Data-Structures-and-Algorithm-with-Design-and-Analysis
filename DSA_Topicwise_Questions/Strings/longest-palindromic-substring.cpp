/*
5. Longest Palindromic Substring
Given a string s, return the longest palindromic substring in s.
Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
*/
#include <string> // Include the necessary header for using strings
#include <iostream>
using namespace std;

class Solution
{
public:
    // Function to check for the longest palindrome centered at L and R
    int check(string &s, int L, int R)
    {
        while (L >= 0 && R < s.length() && s[L] == s[R])
        {
            L--;
            R++;
        }
        return R - L - 1; // Return the length of the palindrome found
    }

    std::string longestPalindrome(std::string s)
    {
        int ans = 0;
        int st = 0;

        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            int len1 = check(s, i, i);     // Check for odd-length palindromes centered at i
            int len2 = check(s, i, i + 1); // Check for even-length palindromes centered at i and i+1

            int len = max(len1, len2);

            if (len > ans)
            {
                ans = len;              // Update the length of the longest palindrome
                st = i - (len - 1) / 2; // Calculate the starting index of the longest palindrome
            }
        }

        // Return the substring of the input string that represents the longest palindrome
        return s.substr(st, ans);
    }
};

int main()
{
    // Example usage:
    string s = "babad";
    Solution solution;
    string longestPalindromicSubstring = solution.longestPalindrome(s);
    cout << "Longest Palindromic Substring: " << longestPalindromicSubstring << endl;
    return 0;
}
