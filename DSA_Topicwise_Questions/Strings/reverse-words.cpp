/*151. Reverse Words in a String
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
Return a string of the words in reverse order concatenated by a single space.
Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.
*/
#include <iostream>
#include <sstream> // Required for stringstream
#include <string>
using namespace std;

class Solution
{
public:
    string reverseWords(std::string s)
    {
        stringstream ss(s); // Create a stringstream to parse the input string
        string rev, w;      // Initialize two strings, `rev` for the reversed result and `w` for a word

        ss >> rev; // Read the first word from the stringstream

        // Continue reading words from the stringstream and prepend them to `rev`
        while (ss >> w)
        {
            rev = w + " " + rev;
        }

        return rev.substr(0, rev.length()); // Return the reversed string (remove trailing space)
    }
};

int main()
{
    Solution solution;            // Create an instance of the Solution class
    string input = "Hello World"; // Example input string

    string result = solution.reverseWords(input); // Call the function to reverse words

    cout << "Reversed String: " << result << std::endl; // Print the result

    return 0;
}
