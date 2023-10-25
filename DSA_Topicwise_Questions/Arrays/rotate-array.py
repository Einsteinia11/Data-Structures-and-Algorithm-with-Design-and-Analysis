# Using temp array
# def rotate(a,k,n):
#     m = a.index(k)
#     temp = []
#     temp = a[m+1:]+a[0:m+1]
#     return temp

# Function to rotate elements one by one
def rotate(a,k,n):
    j = 1
    while j <= k:
        l = a[0] # variable to store initial element of the array
        for i in range(n-1):
            a[i] = a[i+1] # Rotate the elements at (i+1)th index to ith index

        a[n-1] = l # replace the last element with 1st element
        j += 1
    return a #return the rotated array

arr = list(map(int,input().split()))
k = int(input())
n = len(arr)
print(rotate(arr,k,n))