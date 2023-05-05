// 7. Implement Breadth-First Search in a graph 
#include<iostream.h>
#include<stdlib.h>
#define MAX 20
typedef struct Q
{
	int data[MAX];
	int R, F;
}Q;
typedef struct node
{
	struct node *next;
	int vertex;
}node;
void enqueue(Q *, int);
int dequeue(Q *);
int empty(Q *);
int full(Q *);
void BFS(int);
void readgraph();               
void insert(int vi, int vj);    
int discovered[MAX];
int layer[MAX], parent[MAX];
node *G[20];                   
int n;                         
int main()
{
	int i;
	cout<< "\ncreate a node";
	readgraph();
	cout<< "\nBFS";
	cout<< "\nStarting Node No. : ";
	cin>>i;
	BFS(i);
	return 0;
}
void BFS(int v)
{
	int w, i;
	Q q;
	node *p;
	q.R = q.F = -1;               //initialise
	for (i = 1;i<= n;i++)
		discovered[i] = 0;
	enqueue(&q, v);
	int ly = 0;
	layer[v] = ly;
	parent[v] = -1;
	cout<< "\nVisit\t" <<v;
	cout<< "\tand its parent is none and layer is " << layer[v];
	discovered[v] = 1;
	ly = 1;
	while (!empty(&q))
	{
		v = dequeue(&q);
		//insert all undiscovered,adjacent vertices of v into queue
		for (p = G[v];p != NULL;p = p->next)
		{
			w = p->vertex;
			if (discovered[w] == 0)
			{
				parent[w] = v;
				layer[w] = layer[parent[w]] + 1;
				enqueue(&q, w);
				discovered[w] = 1;
				cout<< "\nvisit\t" <<w;
				cout<< "\n Parent of " << w << " is " << parent[w];
				cout<< "\t and its layer is " << layer[w];
			}
		}
		//if(layer[w]!=layer[w-1])
		//ly++;
	}
}
int empty(Q *P)
{
	if (P->R == -1)
		return(1);
	return(0);
}
int full(Q *P)
{
	if (P->R == MAX - 1)
		return(1);
	return(0);
}
void enqueue(Q *P, int x)
{
	if (P->R == -1)
	{
		P->R = P->F = 0;
		P->data[P->R] = x;
	}
	else
	{
		P->R = P->R + 1;
		P->data[P->R] = x;
	}
}
int dequeue(Q *P)
{
	int x;
	x = P->data[P->F];
	if (P->R == P->F)
	{
		P->R = -1;
		P->F = -1;
	}
	else
		P->F = P->F + 1;
	return(x);
}
void readgraph()
{
	int i, vi, vj, no_of_edges;
	cout<< "\nEnter no. of vertices :";
	cin>>n;
	//initialise G[] with NULL
	for (i = 0;i<n;i++)
		G[i] = NULL;
	//read edges and insert them in G[]
	cout<< "\nEnter no of edges :";
	cin>>no_of_edges;
	for (i = 0;i<no_of_edges;i++)
	{
		cout<< "\nEnter an edge (u,v)  :";
		cin>> vi >>vj;
		insert(vi, vj);
		insert(vj, vi);
	}
}
void insert(int vi, int vj)
{
	node *p, *q;
	//acquire memory for the new node
	q = new node;
	q->vertex = vj;
	q->next = NULL;
	//insert the node in the linked list for the vertex no. vi
	if (G[vi] == NULL)
		G[vi] = q;
	else
	{
		// go to the end of linked list
		p = G[vi];
		while (p->next != NULL)
			p = p->next;
		p->next = q;
	}  }
