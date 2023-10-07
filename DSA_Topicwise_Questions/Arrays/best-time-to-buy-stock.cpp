/*
121. Best Time to Buy and Sell Stock
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0. Examples are below*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;          // Initialize the maximum profit to 0
        int minelem = prices[0]; // Initialize the minimum element to the first price in the vector

        // Loop through the vector starting from the second element
        for (int i = 1; i < prices.size(); i++)
        {
            minelem = std::min(prices[i], minelem);           // Update the minimum element if a smaller price is found
            profit = std::max(profit, (prices[i] - minelem)); // Calculate the profit and update it if a larger profit is found
        }
        return profit; // Return the maximum profit
    }
};

int main()
{
    // Example usage:
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution solution;
    int maxProfit = solution.maxProfit(prices);
    cout << "Maximum Profit: " << maxProfit << endl;
    return 0;
}
/*Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.


Constraints:

1 <= prices.length <= 10^5
0 <= prices[i] <= 10^4*/