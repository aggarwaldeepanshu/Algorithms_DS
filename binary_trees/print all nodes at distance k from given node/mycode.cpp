#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *lchild,*rchild;
};

class tree
{
	public:

		int PrintNodes(struct node *,struct node *,int );
};

void PrintDescendant(struct node *root,int k)
{
	if(root==NULL)
	{
		return ;
	}

	if(k==0)
	{
		cout<<root->data<<" ";
		return ;
	}

	PrintDescendant(root->lchild,k-1);
	PrintDescendant(root->rchild,k-1);

	return;
}

int tree::PrintNodes(struct node *root,struct node *ptr,int k)
{
	int l,r;

	if(root==NULL)
		return -1;

	if(root==ptr)
	{
		PrintDescendant(root,k);
		return 0;
	}

	l=PrintNodes(root->lchild,ptr,k);

	if(l!=-1)
	{
		if(l+1==k)
			cout<<root->data<<" ";

		else
			PrintDescendant(root->rchild,k-l-2);

		return l+1;
	}

	r=PrintNodes(root->rchild,ptr,k);
	if(r!=-1)
	{
		if(r+1==k)
			cout<<root->data<<" ";

		else
			PrintDescendant(root->lchild,k-r-2);

		return r+1;
	}
	return -1;
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
	int i,val,k;
	struct node *root,*ptr;
	root=NULL;
	tree ob;
	cout<<"Enter the values for tree"<<endl<<"Enter -1 to exit"<<endl;
	cin>>val;
	while(val!=-1)
	{
		root=insert(root,val);
		cin>>val;
	}
	ptr=root->lchild;
	cout<<"Enter k"<<endl;
	cin>>k;
	ob.PrintNodes(root,ptr,k);
}
