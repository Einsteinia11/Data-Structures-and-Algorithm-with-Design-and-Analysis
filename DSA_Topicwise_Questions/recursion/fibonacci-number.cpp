/*
509. Fibonacci Number
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).*/
#include <iostream>

using namespace std;

class Solution
{
public:
    // Function to calculate the nth Fibonacci number
    int fib(int n)
    {
        // Base cases: Fibonacci numbers for n = 0 and n = 1 are 0 and 1, respectively
        if (n == 0 || n == 1)
        {
            return n;
        }
        // Recursive calculation: Fibonacci number at n is the sum of the previous two Fibonacci numbers
        return fib(n - 1) + fib(n - 2);
    }
};

int main()
{
    Solution solution;
    int n = 10; // Example input, change this to the desired value

    int result = solution.fib(n);

    cout << "Fibonacci number at position " << n << " is: " << result << endl;

    return 0;
}
/*
Example 1:

Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
Example 2:

Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
Example 3:

Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.

Constraints:
0 <= n <= 30*/
