def print_all_possible_ordered_pairs(items):
    for first_item in items:
        for second_item in items:
            print(first_item, second_item)
#Here we're nesting two loops. If our list has n items, our outer loop runs n times and our inner loop runs n times for each iteration of the outer loop, giving us n^2   total prints. Thus this function runs in (O(n^2)) time (or "quadratic time"). If the list has 10 items, we have to print 100 times. If it has 1,000 items, we have to print 1,000,000 times.