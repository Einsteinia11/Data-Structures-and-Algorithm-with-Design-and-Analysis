# Using temp array
# def rotate(a,k,n):
#     m = a.index(k)
#     temp = []
#     temp = a[m+1:]+a[0:m+1]
#     return temp

# Rotating one by one
def rotate(a,k,n):
    j = 1
    while j <= k:
        l = a[0]
        for i in range(n-1):
            a[i] = a[i+1]
        a[n-1] = l
        j += 1
    return a

arr = list(map(int,input().split()))
k = int(input())
n = len(arr)
print(rotate(arr,k,n))