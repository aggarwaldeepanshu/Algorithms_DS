#include<iostream>
using namespace std;
#define max 1000

struct node
{
	int data;
	struct node *lchild,*rchild;
};

class tree
{
	public:

		void roottoleaf(struct node *);
};

void path(struct node *root,int arr[],int size)
{
	if(root==NULL)
		return ;

	arr[size++]=root->data;

	if(root->lchild==NULL&&root->rchild==NULL)
	{
		for(int i=0;i<size;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}
	else
	{
		path(root->lchild,arr,size);
		path(root->rchild,arr,size);
	}
}

void tree::roottoleaf(struct node *root)
{
	int arr[max],size=0;
	path(root,arr,size);
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
	int i,val;
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
	ob.roottoleaf(root);
}
