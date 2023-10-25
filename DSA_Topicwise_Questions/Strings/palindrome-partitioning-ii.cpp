// Definition of the Solution class
class Solution {
public:
    // Function to find the minimum number of cuts required to partition the given string into palindromic substrings
    int minCut(string s) {
        int n = s.size(); // Get the length of the input string
        vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(n, 0)); // 2D vector to store palindrome information
        
        // Populate the dp table to identify palindromic substrings
        for(int i = n-1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                if(i == j) {
                    dp[i][j] = 1; // Single characters are palindromes
                } else if(s[i] == s[j] && i == j-1) {
                    dp[i][j] = 1; // Two characters are palindromes if they are the same
                } else if(s[i] == s[j] && j-i >= 2) {
                    dp[i][j] = dp[i+1][j-1]; // Palindrome property for substrings longer than 2 characters
                }
            }
        }

        vector<int> memo = vector<int>(n+1, n); // Vector to store minimum cuts required for substrings
        memo[n] = 0; // Base case: empty substring requires 0 cuts
        // Calculate minimum cuts for each substring
        for(int i = n-1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                if(dp[i][j]) { // If substring [i, j] is a palindrome
                    memo[i] = min(memo[j+1] + 1, memo[i]); // Update minimum cuts required for substring starting at index i
                }
            }
        }
        return memo[0] - 1; // Return the minimum cuts required for the entire string
    }
};
