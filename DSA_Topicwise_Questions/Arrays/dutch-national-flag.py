def sort012(arr,n):
    i = 0
    zeroidx = 0 
    twoidx = n-1 
    while i <= twoidx:
        if arr[i] == 0:
            arr[zeroidx], arr[i] = arr[i], arr[zeroidx]
            zeroidx += 1
            i += 1
        elif arr[i] == 2:
            arr[twoidx], arr[i] = arr[i], arr[twoidx]
            twoidx -= 1
        else:
            i += 1
    return arr

n = int(input())
arr = list(map(int,input().split()))
print("Sorted array is",sort012(arr,n))