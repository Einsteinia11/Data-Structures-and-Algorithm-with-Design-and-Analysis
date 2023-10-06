/* 32. Longest Valid Parentheses
 Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses
 substring */

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

// Function to find the length of the longest valid parentheses substring
int longestValidParentheses(std::string s)
{
    int maxCount = 0;   // Initialize the maximum length to 0
    std::stack<int> st; // Create a stack to store the indices of parentheses

    st.push(-1); // Push -1 onto the stack as a sentinel value

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '(')
        {
            st.push(i); // Push the index of an opening parenthesis onto the stack
        }
        else
        {
            st.pop(); // Pop the index of the matching opening parenthesis
            if (st.empty())
            {
                st.push(i); // If the stack is empty, push the current index (unmatched closing parenthesis)
            }
            else
            {
                // Calculate the length of the valid parentheses substring by subtracting the top element of the stack
                // from the current index 'i'
                maxCount = std::max(maxCount, i - st.top());
            }
        }
    }

    return maxCount; // Return the maximum length of the valid parentheses substring
}

int main()
{
    std::string input;
    std::cout << "Enter a string with parentheses: ";
    std::cin >> input; // Read the input string from the user

    int result = longestValidParentheses(input);                                        // Call the function to find the longest valid parentheses substring
    std::cout << "Longest valid parentheses substring length: " << result << std::endl; // Print the result

    return 0;
}

/*
 Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0


Constraints:

0 <= s.length <= 3 * 104
s[i] is '(', or ')'.
 */
