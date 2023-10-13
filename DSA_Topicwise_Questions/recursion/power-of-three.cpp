/*
326. Power of Three
Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3^x.
 */
#include <iostream>

using namespace std;

class Solution
{
public:
    // Function to check if a number is a power of three
    bool isPowerOfThree(int n)
    {
        if (n == 0)
        {
            return false; // 0 is not a power of three
        }
        else if (n == 1)
        {
            return true; // 1 is a power of three
        }
        // Check if n is divisible by 3 and recursively check if n/3 is a power of three
        return n % 3 == 0 && isPowerOfThree(n / 3);
    }
};

int main()
{
    Solution solution;
    int n = 27; // Example input

    bool result = solution.isPowerOfThree(n);

    cout << n << " is " << (result ? "a power of three" : "not a power of three") << endl;

    return 0;
}
/*
Example 1:

Input: n = 27
Output: true
Explanation: 27 = 33
Example 2:

Input: n = 0
Output: false
Explanation: There is no x where 3x = 0.
Example 3:

Input: n = -1
Output: false
Explanation: There is no x where 3x = (-1).


Constraints:

-231 <= n <= 231 - 1
*/