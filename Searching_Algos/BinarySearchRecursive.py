def binary_search_recursive(nums, first_index: int, last_index: int, target: int) -> int:
    if (first_index > last_index): # base case: we traversed completely and target not found
        return -1
    mid = first_index + (last_index - first_index) // 2 # middle element index
    if (nums[mid] == target):
        return mid # base case 2: we found target at mid itself
    if (target < nums[mid]):
        # discard right side of array
        return binary_search_recursive(nums, first_index, mid - 1, target)
    else: # target > nums[mid]
        # discard left side of array
        return binary_search_recursive(nums, mid + 1, last_index, target)

nums = [-4, -2, 0, 1, 3, 5, 8, 11, 15, 22, 28]
target = -3
result = binary_search_recursive(nums, 0, len(nums) - 1, target)

if result != -1:
    print(f"Element {target} found at index {result}")
else:
    print(f"Element {target} not found in the array")