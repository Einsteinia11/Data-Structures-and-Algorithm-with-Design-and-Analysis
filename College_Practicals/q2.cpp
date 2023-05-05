// ii. Implement Merge Sort (The program should report the number of comparisons)
#include <iostream>
#include<fstream>
#include<cstdlib>
#include<math.h>
using namespace std;

const int MAX=500;
template<class t>
class merge1{
    t arr[MAX];
public:
    void getdata(t);
    void m(t,t,t,t);
    void msort(t,t,t);
    void display(t);
};
template<class t>
void merge1<t>::getdata(t n){
    for(int i=1;i<=n;i++){
        arr[i]=rand()%10;
    }
}
template<class t>
void merge1<t>::m(t p,t q,t r,t n){
    int count=0;
    ofstream fout("msort.csv",ios::app);
    int l=log2(n);
    int n1=q-p+1;
    int n2=r-q;
    int i,j;
    int L[n1+1],R[n2+1];
    for(i=1;i<=n1;i++){
        L[i]=arr[p+i-1];
    for(j=1;j<=n2;j++){
        R[j]=arr[q+j];
    }
    }
    L[n1+1]=(pow(2,(sizeof(int)*8))/2)-1;
    R[n2+1]=(pow(2,(sizeof(int)*8))/2)-1;
    i=1;
    j=1;
    for(int k=p;k<=r;k++){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i=i+1;
            count++;
        }
        else{
            arr[k]=R[j];
            j=j+1;
            count++;
        }
    }
    fout<<n<<","<<count<<","<<n*l<<","<<l<<","<<n*n<<endl;
    fout.close();
}
template<class t>
void merge1<t>::msort(t p,t r,t n){
   if(p<r){
    int q=floor((p+r)/2);
    msort(p,q,n);
    msort(q+1,r,n);
    m(p,q,r,n);
   }
}
template<class t>
void merge1<t>::display(t n){
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<"\t";
    }
}
int main()
{
    int n=30;
    merge1<int> o1;
    for(int i=0;i<15;i++){
        o1.getdata(n);
        cout<<"\n Values in array are: "<<endl;
        o1.display(n);
        o1.msort(1,n,n);
        cout<<"\n Sorted Values are: "<<endl;
        o1.display(n);
        n+=30;
    }
    return 0;
}
