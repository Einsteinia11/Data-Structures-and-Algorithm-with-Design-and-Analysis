#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<math.h>
using namespace std;
template<class t>
class HeapSort
{
public:
t a[1000];
int count;
int temp;
int size,Heap_size;
void input();
void display();
void MAX_HEAPIFY(t a[],int i);
void Build_MH(t a[]);
int heapsort(t a[]);
int left(int i);
int right(int i);
};
template <class t>
void HeapSort<t>::input()
{
count=0;
cout<<"\n Enter the size of array=";
cin>>size;
for(int i=1;i<=size;i++)
{
a[i]=(rand()%1000+1);
cout<<a[i]<<"\t";
}
Heap_size=size;
}
template <class t>
void HeapSort<t>::display()
{
cout<<"\n Sorted Array:"<<endl;
for (int i=1;i<=size;i++)
cout<<a[i]<<"\t";
cout<<"\n No. of comparison="<<count<<endl;
}
template <class t>
int HeapSort<t>::left(int i)
{
return (i*2);
}
template <class t>
int HeapSort<t>::right(int i)
{
return (i*2+1);
}
template <class t>
void HeapSort<t>::MAX_HEAPIFY(t a[],int i)
{
int l,r,largest;
l=left(i);
r=right(i);
if(l<=Heap_size && a[l]>a[i])
largest=l;
else
largest=i;
count++;
if(r<=Heap_size && a[r]>a[largest])
largest=r;
count++;
if(largest!=i)
{
temp=a[i];
a[i]=a[largest];
a[largest]=temp;
MAX_HEAPIFY(a,largest);
}
}
template <class t>
void HeapSort<t>::Build_MH(t a[])
{
for(int i=size/2;i>=1;i--)
MAX_HEAPIFY(a,i);
}
template <class t>
int HeapSort<t>::heapsort(t a[])
{
Build_MH(a);
for(int i=size;i>=2;i--)
{
temp=a[1];
a[1]=a[i];
a[i]=temp;
Heap_size=Heap_size-1;
MAX_HEAPIFY(a,1);
}
return count;
}
int main()
{
ofstream f("HeapSort.csv");
int c;
char ch='y';
while(ch=='y'||ch=='Y')
{
HeapSort<int> h;
h.input();
c=h.heapsort(h.a);
h.display();
if(f)
{
f<<h.size<<","<<c<<","<<h.size*h.size<<","<<h.size*log(h.size)<<endl;
}
cout<<"\n Do you want to continue?(y/n)";
cin>>ch;
}
f.close();
return 0;
}