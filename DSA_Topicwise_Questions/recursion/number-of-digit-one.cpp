// 233. Number of Digit One
/*
Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

Example 1:

Input: n = 13
Output: 6
Example 2:

Input: n = 0
Output: 0

Constraints:
0 <= n <= 109*/
#include <iostream>
#include <cmath>

using namespace std;

class Solution
{
public:
    // Function to calculate the number of digits in a number
    int getDigitCount(int num)
    {
        if (num == 0)
            return 0;
        int count = 0;

        while (num > 0)
        {
            num = num / 10; // Divide by 10 to move to the next digit
            count++;        // Increment the count for each digit
        }
        return count; // Return the total number of digits
    }

    // Function to count the number of '1's in the digits of a number
    int countOnes(int n)
    {
        if (n <= 0)
            return 0;

        if (n < 10)
            return 1; // If the number is less than 10, there is one '1'

        int numDigits = getDigitCount(n);  // Get the number of digits in n
        int base = pow(10, numDigits - 1); // Calculate the base for the current digit place

        int firstDigit = n / base; // Get the first digit of n
        int remainder = n % base;  // Get the remaining part of n after removing the first digit
        int onesInBase = 0;        // Initialize the count of '1's in the current digit place

        if (firstDigit == 1)
        {
            onesInBase = n - base + 1; // If the first digit is 1, calculate '1's in this digit place
        }
        else
        {
            onesInBase = base; // If the first digit is not 1, all numbers in this digit place have '1's
        }

        // Recursively calculate '1's in the remaining part and for lower digit places
        return onesInBase + firstDigit * countOnes(base - 1) + countOnes(remainder);
    }
};

int main()
{
    // Example usage:
    Solution solution;
    int n = 13;

    int count = solution.countOnes(n);

    cout << "Number of '1's in digits of " << n << ": " << count << endl;

    return 0;
}
