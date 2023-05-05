// 1.i.] Implement Insertion Sort (The program should report the number of comparisons).
#include<iostream>
#include<fstream>
using namespace std;
#include<math.h>
const int siz=500;
template<class T>
class insort
{
public :
    int a[siz];
    void input(int size);
    void output(int size);
    void isort(int size);
};
template<class T>
void insort<T>::input(int size)
{  
for(int i=1;i<size;i++)
    {
        int ele=rand();
        a[i]=ele;
    }
}
template<class T>
void insort<T>::output(int size)
{
cout<<"\n Sorted array : ";
for(int i=1;i<size;i++)
cout<<a[i]<<" ";
}
template<class T>
void insort<T>::isort(int size)
{
    int key,count=0,i;
ofstreamfout("sort.csv",ios::app);
for(int j=2;j<size;j++)
    {
        key=a[j];
i=j-1;
        while(i>0 && a[i]>key)
        {
            a[i+1]=a[i];
i=i-1;
            count++;
        }
        count++;
    a[i+1]=key;
    }
fout<<(size-1)<<" ,"<<count<<","<<log2(size-1)<<","<<(size-1)*log2(size-1)<<","<<(size-1)*(size-1)<<endl;
fout.close();
}
int main()
{  
    int size;
cout<<"\n Enter size of array : ";
cin>>size;
for(int i=0;i<20;i++)
    {
insort<int>o1;
      o1.input( size);
      o1.isort(size);
      o1.output(size);
      size=size+20;
    }
    return 0;
}
