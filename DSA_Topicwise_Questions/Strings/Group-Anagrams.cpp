/*
49. Group Anagrams
Given an array of strings strs, group the anagrams together. You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once. Examples are below the code
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<std::string>> groupAnagrams(vector<string> &strs)
    {
        map<string, vector<string>> mp; // Create a map to group anagrams

        for (auto str : strs)
        {
            string s = str; // Create a copy of the current string

            // Sort the characters in the copy to identify anagrams
            sort(s.begin(), s.end());

            // Use the sorted string as a key in the map and add the original string to the corresponding group
            mp[s].push_back(str);
        }

        vector<vector<string>> ans;

        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            ans.push_back(it->second); // Add the group of anagrams to the result vector
        }

        return ans;
    }
};

int main()
{
    // Example usage:
    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution solution;
    std::vector<std::vector<std::string>> groupedAnagrams = solution.groupAnagrams(strs);

    // Printing the grouped anagrams
    for (auto group : groupedAnagrams)
    {
        for (auto word : group)
        {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

/*
Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]


Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/