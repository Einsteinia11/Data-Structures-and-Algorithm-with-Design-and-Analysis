#include <iostream>
using namespace std;
void insertion_sort(int array[], int size) {
    for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
    cout<<"Sorted array is: "<<endl;
    for(int i = 0; i < size; i++) {
        cout<<array[i]<<", ";
    }
  }
}
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
    insertion_sort(arr, length);
    return 0;
}