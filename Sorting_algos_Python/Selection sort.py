#Function for selection sort
#Sorting by finding minimum index

def selection_sort(arr):
    n= len(arr)
    for i in range(n-1):
        min_index = i
        
        # select the minimum element in every iteration
        for j in range(i+1,n):
            if arr[j] < arr[min_index]:
                min_index = j
        
        arr[i] , arr[min_index] = arr[min_index], arr[i]
        
#Declaring the array
arr = [5,3,1,2,4]
#Calling the function
selection_sort(arr)
#In place array sort
print(arr)