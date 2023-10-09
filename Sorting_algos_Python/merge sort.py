#Function for merge sort merging
def mergesort(arr,l,r,m):
    
    left_half = arr[l:m+1]
    right_half = arr[m+1:r+1]
    
    n = len(left_half)
    m = len(right_half)
    
    i=j=0
    k = l
    
    # Merge the left and right halves into arr
    while(i<n and j<m):
        if left_half[i]<=right_half[j]:
            arr[k] = left_half[i]
            i+=1
        else:
            arr[k] = right_half[j]
            j+=1
        k+=1
        
    # Append any remaining elements from both halves (if any)
    while i < n:
        arr[k] = left_half[i]
        i+=1
        k+=1
    
    while j < m:
        arr[k] = right_half[j]
        j+=1
        k+=1
        
def merge(arr,l,r):
    #Base case
    if l>=r:
        return
    mid = (l+r)//2
    # sort only left part
    merge(arr,l,mid)
    # sort only right part
    merge(arr,mid+1,r)
    # both left and right are sorted so merge them
    mergesort(arr,l,r,mid)
    
arr = [5,3,1,2,4]
n = len(arr)
l = 0
r = n-1
# Calling merge function
merge(arr,l,r)
#Printing sorted function
print(arr)
    