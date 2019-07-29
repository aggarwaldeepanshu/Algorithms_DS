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

		struct node *ExtractLeaves(struct node *,struct node **);
};

struct node *new_node(int val)
{
	struct node *ptr=new node;
	ptr->data=val;
	ptr->lchild=NULL;
	ptr->rchild=NULL;
	return ptr;
}

struct node *tree::ExtractLeaves(struct node *root,struct node **start)
{
	if(root==NULL)
		return NULL;

	struct node *temp;

	if(!root->lchild && !root->rchild)
	{
		if(*start==NULL)
			*start=root;

		else
		{
			(*start)->rchild=root;
			root->lchild=*start;
			*start=root;
		}

		return NULL;
	}
	root->lchild=ExtractLeaves(root->lchild,start);
	root->rchild=ExtractLeaves(root->rchild,start);

	return root;
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

void PrintDLL(struct node *start)
{
	if(start==NULL)
		return;
	PrintDLL(start->lchild);
	cout<<start->data<<" ";
}

void inorder(struct node *root)
{
	if(root==NULL)
		return;

	inorder(root->lchild);
	cout<<root->data<<" ";
	inorder(root->rchild);
}

int main(void)
{
	int i,val,tree_ExtractLeaves;
	struct node *root,*start,*ptr;
	root=NULL;
	start=NULL;
	ptr=NULL;
	tree ob;
	cout<<"Enter the values for tree"<<endl<<"Enter -1 to exit"<<endl;
	cin>>val;
	while(val!=-1)
	{
		root=insert(root,val);
		cin>>val;
	}
	root=ob.ExtractLeaves(root,&start);
	inorder(root);
	cout<<endl;
	PrintDLL(start);
}
