#include <iostream>
#include <vector>

int kadaneAlgorithm(const std::vector<int>& arr) {
    int maxEndingHere = arr[0];  // Initialize the maximum sum ending at the current element
    int maxSoFar = arr[0];      // Initialize the maximum sum so far

    for (size_t i = 1; i < arr.size(); ++i) {
        // Calculate the maximum sum ending at the current element
        maxEndingHere = std::max(arr[i], maxEndingHere + arr[i]);

        // Update the maximum sum so far if needed
        maxSoFar = std::max(maxSoFar, maxEndingHere);
    }

    return maxSoFar;
}

int main() {
    std::vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    int maxSum = kadaneAlgorithm(arr);

    std::cout << "Maximum sum of a subarray: " << maxSum << std::endl;

    return 0;
}

