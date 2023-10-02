#include<iostream>
#include<climits>
#include<queue>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};

Node* newNode(int data){
	Node* node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void printLeftBoundary(Node* root){
	if(root == NULL)
		return;
	cout<<root->data<<" ";
	if(root->left == NULL) printLeftBoundary(root->right);
	else printLeftBoundary(root->left);
}

void printRightBoundary(Node* root){
	if(root == NULL)
		return;
	if(root->right != NULL){
		printRightBoundary(root->right);
		cout<<root->data<<" ";
	}
	else if(root->left != NULL){
		printRightBoundary(root->left);
		cout<<root->data<<" ";
	}
}

void printLeaves(Node* root){
	if(root == NULL)
		return;
	printLeaves(root->left);
	if(root->left == NULL && root->right == NULL)
		cout<<root->data<<" ";
	printLeaves(root->right);
}

Node* BuildTree(int inorder[],int n){
	queue<Node*> q;
	Node* root = newNode(inorder[0]);
	q.push(root);
	int i = 1;
	int j = 2;
	while(i < n && !q.empty()){
		Node* current = q.front();
		q.pop();
		Node* left ;
		Node* right = newNode(inorder[j]);
		if(inorder[i] != INT_MIN) left = newNode(inorder[i]);
		else left = NULL;
		current->left = left;
		if (inorder[j] != INT_MIN && j!=n) right = newNode(inorder[j]);
		else right = NULL;
		current->right = right;
		if(left != NULL) q.push(left);
		if(right != NULL) q.push(right);
		i+=2;
		j+=2;
	}
	return root;
}

int main(){
	int inorder[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
	int n = sizeof(inorder)/sizeof(inorder[0]);
	Node* root = BuildTree(inorder,n);
	cout<<"Boundary Traversal of the tree is: ";
	printLeftBoundary(root);
	printLeaves(root);
	printRightBoundary(root->right);
	cout<<endl;
	return 0;
}
