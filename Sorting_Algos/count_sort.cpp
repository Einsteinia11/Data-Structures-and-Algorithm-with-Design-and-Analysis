#include<bits/stdc++.h>
using namespace std; 

void countSort(int arr[],int n)
{
    // Write your code here.
    int max=arr[0];
    int min=arr[0];
    // to solve problem of negative number we will use concept of correction factor
    // correction factor=abs(min) so that -5->0, -4->1,
    for(int i=1;i<n;i++)
    {
        if(arr[i]>max)
           max=arr[i];
        if(arr[i]<min)
           min=arr[i];   
    }
    int correctionfactor=abs(min);
    // adding correction factor to elements of array to make array positive
    for(int i=0;i<n;i++)
    {
        arr[i]+=correctionfactor;
    }
    // now array to store count will be of length max+countfactor+1
    vector<int> count(max+correctionfactor+1,0);
    for(int i=0;i<n;i++)
    {
        count[arr[i]]++;
    }
    // count now stores the corect position of element in ans array 
    for(int i=1;i<count.size();i++)
    {
        count[i]+=count[i-1];
    }
    int ans[n];
    // in loop we are taking element from array and finding its correct location
    // from count array[count-1 is correct location] and decreasing count by 1
    // decreasing countfactor from arr[i] so that array becomes normal again
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