/*224. Basic Calculator

Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().*/
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        int index = 0; // Index to keep track of the current position in the string
        return calculateExpression(s, index);
    }

private:
    int calculateExpression(string &s, int &index)
    {
        int result = 0;
        int num = 0;
        int sign = 1;

        while (index < s.length())
        {
            char c = s[index++];
            if (isdigit(c))
            {
                num = num * 10 + (c - '0'); // Accumulate digits to form a number
            }
            else if (c == '+')
            {
                result += sign * num;
                num = 0;
                sign = 1;
            }
            else if (c == '-')
            {
                result += sign * num;
                num = 0;
                sign = -1;
            }
            else if (c == '(')
            {
                num = calculateExpression(s, index); // Recursively calculate the expression inside parentheses
            }
            else if (c == ')')
            {
                break; // End of the current expression inside parentheses
            }
        }

        // Calculate the last operand
        result += sign * num;
        return result;
    }
};

int main()
{
    Solution solution;
    string expression = "(1+(4+5+2)-3)+(6+8)";

    int result = solution.calculate(expression);

    cout << "Result: " << result << endl;

    return 0;
}
/*
Example 1:

Input: s = "1 + 1"
Output: 2
Example 2:

Input: s = " 2-1 + 2 "
Output: 3
Example 3:

Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23

Constraints:

1 <= s.length <= 3 * 105
s consists of digits, '+', '-', '(', ')', and ' '.
s represents a valid expression.
'+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
'-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
There will be no two consecutive operators in the input.
Every number and running calculation will fit in a signed 32-bit integer.*/
