#Drop the constants
'''
This is why big O notation rules. When you're calculating the big O complexity of something, you just throw out the constants. So like:
This is O(2n), which we just call O(n).
'''
def print_all_items_twice(items):
    for item in items:
        print(item)

    # Once more, with feeling
    for item in items:
        print(item)


def print_first_item_then_first_half_then_say_hi_100_times(items):
    print(items[0])

    middle_index = len(items) // 2
    index = 0
    while index < middle_index:
        print(items[index])
        index += 1

    for time in range(100):
        print("hi")
        
#This is O(1+n/2+100), which we just call O(n).