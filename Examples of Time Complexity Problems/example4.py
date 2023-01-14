#N could be the actual input, or the size of the input
'''
Both of these functions have O(n) runtime, even though one takes an integer as its input and the other takes a list.
So sometimes n is an actual number that's an input to our function, and other times n is the number of items in an input list (or an input map, or an input object, etc.).
'''
def say_hi_n_times(n):
    for time in range(n):
        print("hi")


def print_all_items(items):
    for item in items:
        print(item)
