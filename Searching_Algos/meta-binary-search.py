# Function to show the working
# of Meta binary search
import math
def bsearch(A, key_to_search):

	n = len(A)
	# Set number of bits to represent
	lg = int(math.log2(n-1)) + 1;

	# largest array index
	#while ((1 << lg) < n - 1):
		#lg += 1

	pos = 0
	for i in range(lg - 1, -1, -1) :
		if (A[pos] == key_to_search):
			return pos

		# Incrementally construct the
		# index of the target value
		new_pos = pos | (1 << i)

		# find the element in one
		# direction and update position
		if ((new_pos < n) and
			(A[new_pos] <= key_to_search)):
			pos = new_pos

	# if element found return
	# pos otherwise -1
	return (pos if(A[pos] == key_to_search) else -1)

# Driver code
if __name__ == "__main__":

	A = [ -2, 10, 100, 250, 32315 ]
	print( bsearch(A, 10))

