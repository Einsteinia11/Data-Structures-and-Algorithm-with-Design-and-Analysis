#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int eggDrop(int eggs, int floors) {
    vector<vector<int>> dp(eggs + 1, vector<int>(floors + 1, 0));

    // Initialize base cases
    for (int i = 1; i <= eggs; i++) {
        dp[i][1] = 1;  // If there is only one floor, one drop is needed
        dp[i][0] = 0;  // If there are no floors, no drops are needed
    }
    for (int j = 1; j <= floors; j++) {
        dp[1][j] = j;  // If there is only one egg, you need to try every floor
    }

    // Fill the table using dynamic programming
    for (int i = 2; i <= eggs; i++) {
        for (int j = 2; j <= floors; j++) {
            dp[i][j] = INT_MAX;

            for (int k = 1; k <= j; k++) {
                int cost = 1 + max(dp[i - 1][k - 1], dp[i][j - k]);

                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[eggs][floors];
}

int main() {
    int eggs, floors;
    cout << "Enter the number of eggs: ";
    cin >> eggs;
    cout << "Enter the number of floors: ";
    cin >> floors;

    int minDrops = eggDrop(eggs, floors);
    cout << "Minimum number of drops required: " << minDrops << endl;

    return 0;
}
