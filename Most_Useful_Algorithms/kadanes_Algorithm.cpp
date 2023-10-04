#include <iostream>
#include <vector>

int kadanesAlgorithm(const std::vector<int>& arr) {
    int maxEndingHere = arr[0];
    int maxSoFar = arr[0];

    for (size_t i = 1; i < arr.size(); ++i) {
        maxEndingHere = std::max(arr[i], maxEndingHere + arr[i]);
        maxSoFar = std::max(maxSoFar, maxEndingHere);
    }

    return maxSoFar;
}

int main() {
    std::vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    int maxSum = kadanesAlgorithm(arr);

    std::cout << "Maximum subarray sum: " << maxSum << std::endl;

    return 0;
}
