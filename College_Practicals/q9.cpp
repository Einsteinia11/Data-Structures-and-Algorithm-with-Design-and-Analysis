// 8. Implement Depth-First Search in a graph 
#include <iostream>
#include<stdlib.h>
using namespace std;
#define MAX 30

template<class t>
class node
{
public:
node *next;
int vertex;
};
template<class t>
class q
{
public:
int data[MAX];
int R,F;
void enqueue(q *, int);
int dequeue(q *);
int empty(q *);
int full(q *);
void DFS(int);
void readgraph();
void insert(int vi, int vj);
int discovered[MAX];
int layer[MAX],parent[MAX];
node<t> *g[MAX];
int n;
};

template<class t>
void q<t>::DFS(int i)
{
node<t> *p;
cout<<"\t "<<i;
p=g[i];
discovered[i]=1;
while(p!=NULL)
{
i=p->vertex;
if(!discovered[i])
DFS(i);
p=p->next;
}
}

template<class t>
int q<t>::empty(q *p)
{
if(p->R==-1)
return(1);
return(0);

}

template<class t>
int q<t>::full(q *p)
{
if(p->R==MAX-1)
return(1);
return(0);
}

template<class t>
void q<t>::enqueue(q *p, int x)
{
if(p->R==-1)
{
p->R=p->F=0;
p->data[p->R]=x;
}
else
{
p->R=p->R+1;
p->data[p->R]=x;
}
}

template<class t>
int q<t>::dequeue(q *p)
{
int x;
x=p->data[p->F];
if(p->R==p->F)
{
p->R=-1;
p->F=-1;
}
else
p->F=p->F+1;
return(x);
}

template<class t>
void q<t>::readgraph()
{
int i,vi,vj, nofedges;
cout<<"\nEnter the number of vertices : ";
cin>>n;
for(i=0;i<n;i++)
g[i]=NULL;
cout<<"\nEnter the number of edges : ";
cin>>nofedges;
for(i=0;i<nofedges;i++)
{
cout<<"\nEnter an edge (u,v) : ";
cin>>vi>>vj;
insert(vi,vj);
insert(vj,vi);
}
}

template<class t>
void q<t>::insert(int vi, int vj)
{
node<t>*p;
node<t>*Q;
Q=new node<t>;
Q->vertex=vj;
Q->next=NULL;
if(g[vi]==NULL)
g[vi]=Q;
else
{
p=g[vi];
while(p->next!=NULL)
p=p->next;
p->next=Q;

}
}

int main()
{
int i;
q<int>o1;
cout<<"\nCreate a node : ";
o1.readgraph();
cout<<"\nDFS";
cout<<"\nStarting node number : ";
cin>>i;
cout<<"\nThe Depth-First-Search is :";
o1.DFS(i);
return 0;
}
