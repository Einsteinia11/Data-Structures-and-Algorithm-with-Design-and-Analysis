#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int main(){
    int t;
    cin>>t;
    while(t--){
        int num;
        cin>>num;
        int c=0;
        while(num>0){
int a=num%10;
if(a==4){c++;}
num=num/10;
        }
        cout<<c<<endl;
    }

return 0;
}