# Drop the less significant terms
# For example:
def print_all_numbers_then_all_pair_sums(numbers):
    print("these are the numbers:")
    for number in numbers:
        print(number)

    print("and these are their sums:")
    for first_number in numbers:
        for second_number in numbers:
            print(first_number + second_number)

'''
Here our runtime is O(n+n2), which we just call O(n2). Even if it was O(n2/2+100n), it would still be O(n2).
Similarly:
            O(n3 + 50 n2 + 10000) is O(n3)
            O((n+30)*(n+5)) is O(n2)
Again, we can get away with this because the less significant terms quickly become, well, less significant as n gets big.
'''