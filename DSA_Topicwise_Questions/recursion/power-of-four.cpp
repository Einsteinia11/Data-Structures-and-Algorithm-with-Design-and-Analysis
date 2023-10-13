/*
342. Power of Four
Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4x.*/
#include <iostream>

using namespace std;

class Solution
{
public:
    bool isPowerOfFour(unsigned int n)
    {
        // Check if n is not zero and has only one set bit using n & (n - 1)
        // Check if the bit at even positions is not set using n & 0xAAAAAAAA
        // If both conditions are true, n is a power of four.
        if (n != 0 && ((n & (n - 1)) == 0) && !(n & 0xAAAAAAAA))
            return true;
        else
            return false;
    }
};

int main()
{
    // Example usage:
    Solution solution;
    unsigned int n = 16;

    bool result = solution.isPowerOfFour(n);

    cout << "Is " << n << " a power of four? " << (result ? "Yes" : "No") << endl;

    return 0;
}

/*
Example 1:

Input: n = 16
Output: true
Example 2:

Input: n = 5
Output: false
Example 3:

Input: n = 1
Output: true


Constraints:

-231 <= n <= 231 - 1
*/