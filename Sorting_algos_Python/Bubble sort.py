#Function of bubble sort

def bubble_sort(arr):
    n = len(arr)
    for i in range(n-1):
        for j in range(n-i-1):
            # Comparing adjacent elements for the bigger element
            if arr[j] > arr[j+1]:
                # Swapping the bigger element
                arr[j], arr[j+1] = arr[j+1], arr[j] 
        # After one iteration of j, we will have largest element in sorted order
        # After second iteration of j, we will have second largest element in sorted order and so on
            
#Declaring the array
arr = [5,3,1,2,4]
#Calling the function
bubble_sort(arr)
#In place array sort
print(arr)