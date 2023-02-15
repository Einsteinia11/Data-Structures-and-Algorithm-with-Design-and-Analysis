#include <iostream>
using namespace std;
void min_heap(int *a, int m, int n){
   int j, t;
   t= a[m];
   j = 2 * m;
   while (j <= n) {
      if (j < n && a[j+1] < a[j])
         j = j + 1;
      if (t < a[j])
         break;
      else if (t >= a[j]) {
         a[j/2] = a[j];
         j = 2 * j;
      }
   }
   a[j/2] = t;
   return;
}
void build_minheap(int *a, int n) {
   int k;
   for(k = n/2; k >= 1; k--) {
      min_heap(a,k,n);
   }
}
int main() {
   int n, i;
   cout<<"enter no of elements of array\n";
   cin>>n;
   int a[30];
   for (i = 1; i <= n; i++) {
      cout<<"enter element"<<" "<<(i)<<endl;
      cin>>a[i];
   }
   build_minheap(a, n);
   cout<<"Min Heap\n";
   for (i = 1; i <= n; i++) {
      cout<<a[i]<<endl;
   }
}