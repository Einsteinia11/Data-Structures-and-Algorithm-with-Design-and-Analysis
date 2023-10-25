# defining a function to sort all 0's,1's & 2's
def sort012(arr,n):
    i = 0
    zeroidx = 0 
    twoidx = n-1 
    while i <= twoidx:
        if arr[i] == 0: # check if the value of the element is 0
            # Move all 0's, by swapping the current element with the element at zeroidx
            arr[zeroidx], arr[i] = arr[i], arr[zeroidx]
            zeroidx += 1
            i += 1
        elif arr[i] == 2: # check if the value of the element is 2
            # Move all 2's, by swapping the current element with the element at twoidx
            arr[twoidx], arr[i] = arr[i], arr[twoidx]
            twoidx -= 1
        else:
            i += 1
    return arr

n = int(input())
arr = list(map(int,input().split()))
print("Sorted array is",sort012(arr,n))