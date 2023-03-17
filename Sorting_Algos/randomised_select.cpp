#include<iostream>
using namespace std;
class randomised_select{
    public:
    int partition(int a[], int p, int r);
    int rnd_select(int a[], int p, int r, int i);
    int rnd_partition(int a[], int p, int r);
};
int randomised_select:: rnd_select(int a[], int p, int r, int i){
    if(p == r) return a[p];
    int q = rnd_partition(a, p, r);
    int k = q-p+1;
    if(i == k) return a[q];
    else if(i<k) return rnd_select(a, p, q-1, i);
    else return rnd_select(a, q+1, r, i-k);
}
int randomised_select:: rnd_partition(int a[], int p, int r){
    int i = rand()%r +1;
    swap(a[i], a[r]);
    return partition(a,p,r)
}
int randomised_select:: partition(int a[], int p, int r){
    int x = a[r];
    int i = p-1;
    for(int j = p; j<r; j++){
        if(a[j]<=x){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[r]);
    return i+1;
}
int main(){
    int n = 20; 
    int A[n];
    for(int i = 1; i<=n; i++){
        A[i] = rand()%100;
        cout<<A[i]<<endl;
    }
    randomised_select obj;
    int i;
    char ch = 'y';
    while(ch == 'y'){
        cout<<"Enter the value of i: "<<endl;
        cin>>i;
        cout<<obj.rnd_select(A, 1, n-1, i)<<endl;
        cout<<"Enter y to continue"<<endl;
        cin>>ch;
    }
    return 0;
}