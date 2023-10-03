# Python3 implementation of the approach
# Function to search key in the given array


def sentinelSearch(arr, n, key):

	# Last element of the array
	last = arr[n - 1]

	# Element to be searched is
	# placed at the last index
	arr[n - 1] = key
	i = 0

	while (arr[i] != key):
		i += 1

	# Put the last element back
	arr[n - 1] = last

	if ((i < n - 1) or (arr[n - 1] == key)):
		print(key, "is present at index", i)
	else:
		print("Element Not found")



arr = [10, 20, 180, 30, 60, 50, 110, 100, 70]
n = len(arr)
key = 180

sentinelSearch(arr, n, key)

