#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int l=0,r=n-1,c=0;
    while(l<r){
        if(a[l]>a[r]){
            a[l]-=a[r];
            r--;
            c++;
        }
        else if(a[l]<a[r]){
            a[r]-=a[l];
            l++;
            c++;
        }
        else{
            l++;r--;
        }
// cout<<a[l]<<"  "<<a[r]<<" "<<l<<"  "<<r<<endl;
    }
    cout<<c<<endl;
}
return 0;
}