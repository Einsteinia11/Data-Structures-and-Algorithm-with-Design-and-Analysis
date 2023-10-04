#include<bits/stdc++.h>
using namespace std;
/**
 In this algo we have to find the contiguous sub-array(containing at least one number) which has the maximum sum and return its sum.
 **/
long long kandane(int arr[], int n){
        
        // Your code here
        long long sum=0,maxi=INT_MIN;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            maxi=max(maxi,sum);
            if(sum<0){
                sum=0;
            }
        }
        return maxi;
    }

int main(){
        int n;
        cin>>n;
        int*arr=new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        long long ans=kandane(arr,n);
        cout<<ans<<endl;
        return 0;
    }