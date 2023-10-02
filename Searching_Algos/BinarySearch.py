def binary_search(arr, target):
    left, right = 0, len(arr) - 1

    while left <= right:
        mid = (left + right) // 2  # Calculate the middle index

        if arr[mid] == target:
            return mid  # Target found, return its index
        elif arr[mid] < target:
            left = mid + 1  # Adjust the left bound
        else:
            right = mid - 1  # Adjust the right bound

    return -1  # Target not found in the array

# Example usage:
arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
target = 6
result = binary_search(arr, target)

if result != -1:
    print(f"Element {target} found at index {result}")
else:
    print(f"Element {target} not found in the array")
