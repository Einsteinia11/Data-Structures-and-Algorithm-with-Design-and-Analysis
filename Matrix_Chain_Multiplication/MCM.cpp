#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to find the minimum number of scalar multiplications needed to compute the product of matrices
int matrixChainMultiplication(vector<int>& dimensions) {
    int n = dimensions.size() - 1; // Number of matrices
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Initialize dp[i][i] to 0 since a single matrix has no cost
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }

    // Fill the table using dynamic programming
    for (int length = 2; length <= n; length++) {
        for (int i = 0; i < n - length + 1; i++) {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i] * dimensions[k + 1] * dimensions[j + 1];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    // The result is stored in dp[0][n-1]
    return dp[0][n - 1];
}

int main() {
    int n; // Number of matrices
    cin >> n;

    vector<int> dimensions(n + 1); // Dimensions of matrices

    // Input the dimensions of each matrix
    for (int i = 0; i <= n; i++) {
        cin >> dimensions[i];
    }

    int minScalarMultiplications = matrixChainMultiplication(dimensions);
    cout << "Minimum scalar multiplications: " << minScalarMultiplications << endl;

    return 0;
}
