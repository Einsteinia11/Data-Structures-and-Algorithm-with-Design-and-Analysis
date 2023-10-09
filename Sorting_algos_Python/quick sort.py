#Function for quick sort
def quickSort(arr):
    #Base case
    if len(arr) <=1:
        return arr
    else:
        pivot = arr[0]
        #Left half contains element which is less than pivot element
        left_half = [x for x in arr[1:] if x<pivot]
        #Right half contains element which is greater than or equal to pivot element
        right_half = [x for x in arr[1:] if x>=pivot]
        #Recurrsively merging left and right half
        return quickSort(left_half)+[pivot]+quickSort(right_half)

arr = [5,3,1,2,4]
#Calling the function
sorted_arr = quickSort(arr)
#Print the sorted array
print(sorted_arr)