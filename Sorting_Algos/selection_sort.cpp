#include <iostream>
using namespace std;
class selection_sort{
    public:
    int n;
    int arr[];
    selection_sort(){
        cout<<"Enter the value of n: "<<endl;
        cin>>n;
    }
    void insert(){
        for(int i = 0; i<n; i++){
            cout<<"Enter the value at"<<i<<"th position"<<endl;
            cin>>arr[i];
        }
    }
    void sort(){
        int i, j, small;
        for(int i= 0; i<n; i++){
            small = i;
            for(int j= i+1; j<n; j++){
                if(arr[j]<arr[small]){
                    small = j;
                }
            }
            int temp = arr[small];
            arr[small] = arr[i];
            arr[i] = temp;
        }
        for(int i = 0; i<n; i++){
            cout<<arr[i]<<", ";
        }
        cout<<endl;
    }
};

int main(){
    //This program is written by kajal
    
    selection_sort obj;
    obj.insert();
    obj.sort();

    return 0;
}