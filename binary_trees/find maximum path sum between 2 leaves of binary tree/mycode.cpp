#include<iostream>
#include<climits>
using namespace std;

struct node
{
	int data;
	struct node *lchild,*rchild;
};

class tree
{
	public:

		int MaxPath(struct node *,int *);
};

int max(int a,int b)
{
	return (a>b)?a:b;
}

int tree::MaxPath(struct node *root,int *k)
{
	int lchild=0,rchild=0;
	if(root==NULL)
		return 0;

	if(root->lchild==NULL && root->rchild==NULL)
		return root->data;

	lchild=MaxPath(root->lchild,k);
	rchild=MaxPath(root->rchild,k);

	if(root->lchild && root->rchild)
	{
		*k=max(*k,lchild+rchild+root->data);
		return max(lchild,rchild)+root->data;
	}

	if(root->lchild)
		return lchild+root->data;

	else if(root->rchild)
		return rchild+root->data;
}

struct node *new_node(int val)
{
	struct node *ptr=new node;
	ptr->data=val;
	ptr->lchild=NULL;
	ptr->rchild=NULL;
	return ptr;
}

struct node *insert(struct node *root,int val)
{
	if(root==NULL)
		return new_node(val);
	else if(val<root->data)
		root->lchild=insert(root->lchild,val);
	else
		root->rchild=insert(root->rchild,val);

	return root;
}

int main(void)
{
	int i,val,k=INT_MIN;
	struct node *root;
	root=NULL;
	tree ob;
	cout<<"Enter the values for tree"<<endl<<"Enter -1 to exit"<<endl;
	cin>>val;
	while(val!=-1)
	{
		root=insert(root,val);
		cin>>val;
	}
	ob.MaxPath(root,&k);
	cout<<"maximum sum is "<<k<<endl;
}
