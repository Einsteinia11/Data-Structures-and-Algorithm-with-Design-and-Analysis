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
    }
    cout<<endl;
    cout<<"Array after sorting: "<<endl;
    for(int i = 0; i < length; i++) {
        cout<<array[i]<<", ";
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
    cout<<endl;
    insertion_sort(arr, length);
    return 0;
}