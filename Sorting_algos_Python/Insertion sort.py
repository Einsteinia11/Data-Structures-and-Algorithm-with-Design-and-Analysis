#Function for selection sort

def insertion_sort(arr):
    n= len(arr)
    for i in range(1,n):
        
        key = arr[i]
        j = i -1
        
        #Move elements one position ahead of the current position
        #They move only when key is lesser than the current element
        while(j>=0 and key < arr[j]):
            arr[j+1] = arr[j]
            j= j - 1
        
        #Finally place the key element in its place
        arr[j+1] = key
        
#Declaring the array
arr = [5,3,1,2,4]
#Calling the function
insertion_sort(arr)
#In place array sort
print(arr)