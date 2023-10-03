def linear_search_recursive(nums, index: int, target: int) -> int:
    if index > len(nums) - 1: # base case 1 :when index counter exceeds end of list
        return -1
    if nums[index] == target: # base case 2: when index == target
        return index

    return linear_search_recursive(nums, index + 1, target) # increment index

nums = [34, 11, 5, 52, 99, 15, 55, 12, 8, 2, 1, -5]
target = 12
result = linear_search_recursive(nums, 0, target)

if result != -1:
    print(f"Element {target} found at index {result}")
else:
    print(f"Element {target} not found in the array")