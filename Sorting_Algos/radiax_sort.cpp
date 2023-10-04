// Radix Sort is a linear sorting algorithm that sorts elements by processing them digit by digit. 
// It is an efficient sorting algorithm for integers or strings with fixed-size keys. 

#include<bits/stdc++.h>
using namespace std;
int nth(int value,int digit)
{
    // nth function return nth digit in a digit
    // if no=121772 ans digit= 5 it will return 2
    string val=to_string(value);
    if(val.size()<digit)
        return 0;
    else
    {
        return val[val.size()-digit]-'0';
    }
}
void radixSort(int arr[],int n)
{
    // creating 9 queues to store numbers based on their digits 
    vector<queue<int>> queues(10);
    int maxi=0;
    // calculating the max number ina n array and calculating number of digits in it
    for(int i=0;i<n;i++)
        if(arr[i]>maxi)
            maxi=arr[i];
    int maxDigit= to_string(maxi).size();

    // pushing number into their corresponding buckets based on digits
    for(int i=0;i<maxDigit;i++)
    {
        for(int j=0;j<n;j++)
        {
           queues[nth(arr[j],i+1)].push(arr[j]);
        }
        int p=0;
        for(int j=0;j<10;j++){
                // popping element from queue to get their correct position after nth operation
                while(!queues[j].empty())
                {
                    arr[p]=queues[j].front();
                    queues[j].pop();
                    p++;
                }
        }
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
    int arr[6]={222112,22421,286560,0,1111111118,171};
    int n=6;
    cout<<"Before Sorting :"<<endl;
    print(arr,n);
    radixSort(arr,n);
    cout<<"After Sorting :"<<endl;
    print(arr,n);
}