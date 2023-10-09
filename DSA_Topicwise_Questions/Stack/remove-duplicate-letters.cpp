/*
316. Remove Duplicate Letters
Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        unordered_map<char, int> freq; // Create a hash map to store character frequencies
        for (auto it : s)
        {
            freq[it]++;
        }

        vector<bool> visited(26, false); // Create a vector to mark visited characters
        stack<char> st;                  // Create a stack to build the result string

        for (int i = 0; i < s.length(); i++)
        {
            freq[s[i]]--;

            if (visited[s[i] - 'a'])
            {
                continue;
            }
            while (!st.empty() && s[i] < st.top() && freq[st.top()] > 0)
            {
                visited[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            visited[s[i] - 'a'] = true;
        }
        string res = "";
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    string s = "bcabc"; // Replace with your input string

    Solution solution;

    string result = solution.removeDuplicateLetters(s);

    cout << "Result after removing duplicate letters: " << result << endl;

    return 0;
}

/*
Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"

Constraints:

1 <= s.length <= 10^4
s consists of lowercase English letters.
*/