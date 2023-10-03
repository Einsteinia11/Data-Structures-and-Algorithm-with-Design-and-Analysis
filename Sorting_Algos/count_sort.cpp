#include<bits/stdc++.h>
using namespace std;
void countSort(int arr[],int n)
{
    int max=INT_MIN,min=INT_MAX;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>max) max=arr[i];
        if(arr[i]<min) min=arr[i];
    }
    int correctionfactor=abs(min);
    for(int i=0;i<n;i++)
    {
        arr[i]+=correctionfactor;
    }
    vector<int> count(max+correctionfactor+1,0);
    for(int i=0;i<n;i++)
    {
        count[arr[i]]++;
    }
    for(int i=1;i<count.size();i++)
    {
        count[i]+=count[i-1];
    }
    int ans[n];
    for(int i=n-1;i>=0;i--)
    {
        ans[count[arr[i]]-1]=arr[i]-correctionfactor;
        count[arr[i]]--;
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=ans[i];
    }
}

void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int arr[6]={22,21,18,0,16,171};
    int n=6;
    cout<<"Before Sorting :"<<endl;
    print(arr,n);
    countSort(arr,n);
    cout<<"After Sorting :"<<endl;
    print(arr,n);
}