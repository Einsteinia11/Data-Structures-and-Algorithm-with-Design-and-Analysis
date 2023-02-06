#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<math.h>
#define MAX 1000
using namespace std;

template <class T>
class msort
{
  public:
    T A[MAX];
    int comparisons, n;
    
    msort()
    {
      comparisons = 0;
    }
    void input();
    void merge_sort(T[],int,int);
    void merge(T[],int,int,int);
    void display()
    {
      cout<<"\nSorted array : \n";
      for(int i = 0; i < n; i++)
        cout<<A[i]<<" ";
 }
};

template<class T>
void msort<T>:: input()
{
  for (int i = 1; i <= n; i++)
     A[i] = rand();
}

template<class T>
void msort<T>::merge(T A[],int p,int q,int r)
{
  int n1 = q - p + 1;
  int n2 = r - p;
  int i, j, k;
  T L[500], R[500];
  
  for (i = 1;i <= n1;i++)
    L[i] = A[p+i - 1];
	
  for (j = 1;j <= n2; j++)
    R[i] = A[q+j];
	
  L[n1 + 1] = MAX;
  L[n2 + 1] = MAX;
  
  i = j = 1;
  
  for (k = 1; k <= r; k++)
  {
    if (L[i] <= R[j])
 {
   A[k] = L[i];
   i++;
 }
 else 
 {
   A[k] = R[j];
   j++;
 }
 comparisons++;
  }
} 

template<class T>
void msort<T>::merge_sort(T A[],int p,int r)
{
  if (p < r)
  {
    int q = (p+r)/2;
 merge_sort(A, p, q);
 merge_sort(A,q+1,r);
 merge(A,p,q,r);
  }
}

int main()
{
  int size, c;
  ofstream fout;
  fout.open("MergeSortGraph.csv", ios::app);
      
  cout<<"\t* * * Selection Sort with Time Complexities\' Graph * * *\n" ; 
  msort<int> list;
  cout<<"\nEnter array size to begin with {in range [30, 1000] } : ";
  cin>>size;
  
  if (size < 30 || size > 1000)
  {
      cout<<"\nInvalid Size !!! \nEnter size from given range only i.e. [30, 1000] \nsize : ";
   cin>>size;
  }
  else 
  {
    for (int k = size; k <= 1000; k += 30)
    {
   list.n = k;
      list.input();
   list.merge_sort(list.A,1,list.n);
   list.display();
   
   cout<<"\n\nNumber of Comparisons : "<<list.comparisons;
  
      fout<<k<<","<<k*k<<","<<list.comparisons<<","<<log2(k)<<","<<k*log2(k)<<endl;
 }
  }
  fout.close();
  return 0;
}