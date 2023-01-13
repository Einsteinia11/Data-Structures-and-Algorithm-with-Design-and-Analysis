#include <iostream>
using namespace std;
void insertion_sort(int array[], int length){
    for(int i = 1; i < length; i++){
        int key = array[i];
        cout<<"key = "<<key<<endl;
        int j = i-1;
        while(key < array[j] && j>=0){
            array[j+1] = array[j];
            j--;
        }
        cout<<endl;
        array[j+1] = key; 
        // for(int i = 0; i < length; i++) {
        //     cout<<array[i]<<", ";
        // }
        // cout<<endl;
    }
    cout<<endl;
    cout<<"Array after sorting: "<<endl;
    for(int i = 0; i < length; i++) {
        cout<<array[i]<<", ";
    }
}
/* Example Run:
Suppose we have an array [43, 5, 6, 1]
key = 5
[5, 43, 6, 1]
key = 6
[5, 6, 43, 1]
key = 1
[1, 5, 6, 43]

Now Let's talk about it's Time Complexity,
1. Best Case: for example When the array is in Ascending order
ex. array = [10, 20, 30, 40, 50, 60]
So the Numbers of Camparisons and swapping will be,
   No. of Camparisons   |    No. of Swapping
           0            |          0
           1            |          0
           .            |          .    // here (.) means same as above
           .            |          .
        (n-1)           |          .

    So from here we will consider the upper bound value of (n-1) which is n.
    so the Time Complexity for the best case would be O(n).

2. Worst case: For example When the array is in Descending order
ex. array = [60, 50, 40, 30, 20, 10]
So the Numbers of Camparisons and swapping will be,
   No. of Camparisons   |    No. of Swapping
           0            |          0
           1            |          1
           2            |          2    // here (.) means same as above
           3            |          3
           .            |          .
        (n-1)           |          (n-1)
    So this will be solved as n(n-1)/2 which will become n^2.n/2 here we have to consider the bigger term which is n^2
    so the Time Complexity for the worst case would be O(n^2)
 3. Likewise the average case will be similar to Worst case so it's Time complexity would be O(n^2).
*/
int main(){
    int length;
    cout<<"Enter the length of the array: ";
    cin>>length;
    int arr[length];
    cout<<"Enter the array: ";
    for(int i = 0; i < length; i++){
        cin>>arr[i];
    }
    cout<<endl;
    cout<<"Your entered array is: "<<endl;
    for(int i = 0; i < length; i++){
        cout<<arr[i]<<", ";
    }
    cout<<endl;
    insertion_sort(arr, length);
    return 0;
}